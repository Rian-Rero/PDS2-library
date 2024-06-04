#include "dataBase.hpp"
#include "users.hpp"
#include <iostream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/sha.h>     // Para SHA-256
#include <cryptopp/hex.h>     // Para codificação hexadecimal
#include <cryptopp/filters.h> // Para Crypto++ filters
#include <sstream>            // Adicionando inclusão para stringstream
#include <thread>             // Para std::this_thread::sleep_for
#include <chrono>             // Para std::chrono::milliseconds

using namespace std;
using namespace CryptoPP;
SHA256 sha256;

// Constructor

Database::Database(const string &filename)
{
    int rc = sqlite3_open(filename.c_str(), &db);
    if (rc)
    {
        cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(db) << endl;
        throw runtime_error("Erro ao abrir o banco de dados");
    }

    // Criação da tabela Livros
    const char *sql_create_table_livros =
        "CREATE TABLE IF NOT EXISTS Livros ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
        "Titulo TEXT NOT NULL,"
        "Autor TEXT NOT NULL,"
        "Emprestado INTEGER NOT NULL,"
        "DataCadastro TEXT NOT NULL,"
        "AudioBook INTEGER NOT NULL DEFAULT 0"
        ");";

    rc = sqlite3_exec(db, sql_create_table_livros, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao criar a tabela Livros: " << sqlite3_errmsg(db) << endl;
        throw runtime_error("Erro ao criar a tabela Livros");
    }

    // Criação da tabela Usuarios
    const char *sql_create_table_usuarios =
        "CREATE TABLE IF NOT EXISTS Usuarios ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
        "Nome TEXT NOT NULL,"
        "Email TEXT NOT NULL,"
        "Senha TEXT NOT NULL,"
        "Admin INTEGER NOT NULL DEFAULT 0,"
        "Cargo TEXT"
        ");";

    rc = sqlite3_exec(db, sql_create_table_usuarios, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao criar a tabela Usuarios: " << sqlite3_errmsg(db) << endl;
        throw runtime_error("Erro ao criar a tabela Usuarios");
    }

    // Criação da tabaela de histórico de livros emprestados

    const char *sql_create_table_historico_emprestimos =
        "CREATE TABLE IF NOT EXISTS HistoricoEmprestimos ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
        "UsuarioID INTEGER NOT NULL,"
        "LivroID INTEGER NOT NULL,"
        "DataEmprestimo TEXT NOT NULL,"
        "DataDevolucao TEXT,"
        "FOREIGN KEY(UsuarioID) REFERENCES Usuarios(ID),"
        "FOREIGN KEY(LivroID) REFERENCES Livros(ID)"
        ");";

    rc = sqlite3_exec(db, sql_create_table_historico_emprestimos, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao criar a tabela HistoricoEmprestimos: " << sqlite3_errmsg(db) << endl;
        throw runtime_error("Erro ao criar a tabela HistoricoEmprestimos");
    }

    // Criação da tabela de livros alugados

    const char *sql_create_table_livros_alugados =
        "CREATE TABLE IF NOT EXISTS LivrosAlugados ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
        "UsuarioID INTEGER NOT NULL,"
        "LivroID INTEGER NOT NULL,"
        "DataEmprestimo TEXT NOT NULL,"
        "FOREIGN KEY(UsuarioID) REFERENCES Usuarios(ID),"
        "FOREIGN KEY(LivroID) REFERENCES Livros(ID)"
        ");";

    rc = sqlite3_exec(db, sql_create_table_livros_alugados, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao criar a tabela LivrosAlugados: " << sqlite3_errmsg(db) << endl;
        throw runtime_error("Erro ao criar a tabela LivrosAlugados");
    }
}

// Destructor

Database::~Database()
{
    sqlite3_close(db);
}

// Books

void Database::createBook(const string &title, const string &author, bool borrowed, const string &date)
{
    const char *sql_insert =
        "INSERT INTO Livros (Titulo, Autor, Emprestado, DataCadastro) VALUES (?, ?, ?, ?);";
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_insert, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sqlite3_bind_text(stmt, 1, title.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, author.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 3, borrowed ? 1 : 0);
    sqlite3_bind_text(stmt, 4, date.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        cerr << "Erro ao inserir o livro: " << sqlite3_errmsg(db) << endl;
    }
    else
    {
        cout << "Livro inserido com sucesso!" << endl;
    }

    sqlite3_finalize(stmt);
};

void Database::getAllBooks()
{
    const char *sql_select_all = "SELECT * FROM Livros;";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_select_all, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    cout << "Todos os livros:\n";

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *title = sqlite3_column_text(stmt, 1);
        const unsigned char *author = sqlite3_column_text(stmt, 2);
        int borrowed = sqlite3_column_int(stmt, 3);
        const unsigned char *date = sqlite3_column_text(stmt, 4);

        cout << "ID: " << id << ", Título: " << title << ", Autor: " << author
             << ", Emprestado: " << (borrowed ? "Sim" : "Não") << ", Data de Cadastro: " << date << endl;
    }

    sqlite3_finalize(stmt);
};

void Database::getBook(const string &name)
{
    if (name.empty())
    {
        cerr << "Erro: Nome do livro vazio." << endl;
        return;
    }

    const char *sql_select_book = "SELECT * FROM Livros WHERE Titulo LIKE ?;";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_select_book, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    // String de busca com curingas para filtrar parte do título
    string searchName = "%" + name + "%";
    sqlite3_bind_text(stmt, 1, searchName.c_str(), -1, SQLITE_STATIC);

    bool found = false;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        found = true;
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *title = sqlite3_column_text(stmt, 1);
        const unsigned char *author = sqlite3_column_text(stmt, 2);
        int borrowed = sqlite3_column_int(stmt, 3);
        const unsigned char *date = sqlite3_column_text(stmt, 4);

        cout << "ID: " << id << ", Título: " << title << ", Autor: " << author
             << ", Emprestado: " << (borrowed ? "Sim" : "Não") << ", Data de Cadastro: " << date << endl;
    }

    sqlite3_finalize(stmt);

    if (!found)
    {
        cout << "Nenhum livro encontrado com o título contendo '" << name << "'." << endl;
    }
}

void Database::getBookByAuthor(const string &author)
{
    if (author.empty())
    {
        cerr << "Erro: Nome do autor vazio." << endl;
        return;
    }

    const char *sql_select_book = "SELECT * FROM Livros WHERE Autor LIKE ?;";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_select_book, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    // String de busca com curingas para filtrar parte do autor
    string searchAuthor = "%" + author + "%";
    sqlite3_bind_text(stmt, 1, searchAuthor.c_str(), -1, SQLITE_STATIC);

    bool found = false;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        found = true;
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *title = sqlite3_column_text(stmt, 1);
        const unsigned char *author = sqlite3_column_text(stmt, 2);
        int borrowed = sqlite3_column_int(stmt, 3);
        const unsigned char *date = sqlite3_column_text(stmt, 4);

        cout << "ID: " << id << ", Título: " << title << ", Autor: " << author
             << ", Emprestado: " << (borrowed ? "Sim" : "Não") << ", Data de Cadastro: " << date << endl;
    }

    sqlite3_finalize(stmt);

    if (!found)
    {
        cout << "Nenhum livro encontrado com o autor contendo '" << author << "'." << endl;
    }
}

string Database::getBookName(int ID)
{
    const char *sql_select_book = "SELECT Titulo FROM Livros WHERE ID = ?;";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_select_book, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return "";
    }

    sqlite3_bind_int(stmt, 1, ID);

    if ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        const unsigned char *title = sqlite3_column_text(stmt, 0);
        string bookName = reinterpret_cast<const char *>(title);
        sqlite3_finalize(stmt);
        return bookName;
    }
    else
    {
        cout << "Livro não encontrado." << endl;
        sqlite3_finalize(stmt);
        return "";
    }
}

void Database::getAvailableBooks(bool borrowed)
{
    const char *sql_select_book = "SELECT * FROM Livros WHERE Emprestado = ?;";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_select_book, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, borrowed ? 1 : 0);

    bool found = false;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        found = true;
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *title = sqlite3_column_text(stmt, 1);
        const unsigned char *author = sqlite3_column_text(stmt, 2);
        int borrowed = sqlite3_column_int(stmt, 3);
        const unsigned char *date = sqlite3_column_text(stmt, 4);

        cout << "ID: " << id << ", Título: " << title << ", Autor: " << author
             << ", Emprestado: " << (borrowed ? "Sim" : "Não") << ", Data de Cadastro: " << date << endl;
    }

    sqlite3_finalize(stmt);

    if (!found)
    {
        cout << "Nenhum livro encontrado com o status de  " << (borrowed ? "Disponível" : "Emprestado") << "'." << endl;
    }
}

void Database::rentBook(int bookID, int userID)
{
    // Atualizar o status do livro para emprestado na tabela Livros
    const char *sql_update = "UPDATE Livros SET Emprestado = 1 WHERE ID = ?;";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_update, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, bookID);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        cerr << "Erro ao atualizar o livro: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);

    // Inserir o empréstimo na tabela HistoricoEmprestimos
    const char *sql_insert_historico =
        "INSERT INTO HistoricoEmprestimos (UsuarioID, LivroID, DataEmprestimo) VALUES (?, ?, datetime('now'));";

    rc = sqlite3_prepare_v2(db, sql_insert_historico, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta de histórico: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, userID);
    sqlite3_bind_int(stmt, 2, bookID);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        cerr << "Erro ao registrar no histórico de empréstimos: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);

    // Inserir o empréstimo na tabela LivrosAlugados
    const char *sql_insert_alugados =
        "INSERT INTO LivrosAlugados (UsuarioID, LivroID, DataEmprestimo) VALUES (?, ?, datetime('now'));";

    rc = sqlite3_prepare_v2(db, sql_insert_alugados, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta de livros alugados: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, userID);
    sqlite3_bind_int(stmt, 2, bookID);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        cerr << "Erro ao registrar no livros alugados: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);

    cout << "Livro emprestado com sucesso!" << endl;
}

void Database::returnBook(int BookID, int userID)
{
    const char *sql_update = "UPDATE Livros SET Emprestado = 0 WHERE ID = ?;";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_update, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, BookID);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        cerr << "Erro ao atualizar o livro: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        return;
    }
    sqlite3_finalize(stmt);

    // Atualizar a data de devolução na tabela HistoricoEmprestimos
    const char *sql_update_historico = "UPDATE HistoricoEmprestimos SET DataDevolucao = datetime('now') WHERE LivroID = ? AND UsuarioID = ? AND DataDevolucao IS NULL;";

    rc = sqlite3_prepare_v2(db, sql_update_historico, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta de histórico: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, BookID);
    sqlite3_bind_int(stmt, 2, userID);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        cerr << "Erro ao registrar a devolução no histórico de empréstimos: " << sqlite3_errmsg(db) << endl;
    }
    sqlite3_finalize(stmt);

    // Remover o livro da tabela LivrosAlugados
    const char *sql_delete_alugados = "DELETE FROM LivrosAlugados WHERE LivroID = ? AND UsuarioID = ?;";

    rc = sqlite3_prepare_v2(db, sql_delete_alugados, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta de livros alugados: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, BookID);
}

void Database::getBorrowedHistory(int userID)
{
    const char *sql_select_history = "SELECT * FROM HistoricoEmprestimos WHERE UsuarioID = ?;";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_select_history, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, userID);

    cout << "Histórico de empréstimos:\n";

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        int bookID = sqlite3_column_int(stmt, 2);
        const unsigned char *dateBorrowed = sqlite3_column_text(stmt, 3);
        const unsigned char *dateReturned = sqlite3_column_text(stmt, 4);

        cout << "ID: " << id << ", LivroID: " << bookID << ", Data de Empréstimo: " << dateBorrowed
             << ", Data de Devolução: " << (dateReturned ? (const char *)dateReturned : "Ainda não devolvido") << endl;
    }

    sqlite3_finalize(stmt);
}

// preciso que apareca o nome do livro tbm
void Database::getCurrentBorrowedBooks(int userID)
{
    const char *sql_select_books = "SELECT * FROM LivrosAlugados WHERE UsuarioID = ?;";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_select_books, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, userID);

    cout << "Livros atualmente alugados:\n";

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        int bookID = sqlite3_column_int(stmt, 2);
        const unsigned char *dateBorrowed = sqlite3_column_text(stmt, 3);
        string bookName = getBookName(bookID);

        cout << "ID: " << id << ", Nome: " << bookName << ", LivroID: " << bookID << ", Data de Empréstimo: " << dateBorrowed << endl;
    }

    sqlite3_finalize(stmt);
}

// Users

void Database::createUser(const string &nome, const string &email, const string &senha)
{
    // Verificar se o email já está em uso
    const char *sql_check_email =
        "SELECT COUNT(*) FROM Usuarios WHERE Email = ?;";

    sqlite3_stmt *stmt_check_email;
    int rc = sqlite3_prepare_v2(db, sql_check_email, -1, &stmt_check_email, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sqlite3_bind_text(stmt_check_email, 1, email.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt_check_email);
    if (rc == SQLITE_ROW && sqlite3_column_int(stmt_check_email, 0) > 0)
    {
        cerr << "E-mail já em uso." << endl;
        sqlite3_finalize(stmt_check_email);
        return;
    }

    sqlite3_finalize(stmt_check_email);

    // Gerar hash da senha
    SHA256 sha256;
    CryptoPP::byte digest[SHA256::DIGESTSIZE];
    sha256.CalculateDigest(digest, reinterpret_cast<const CryptoPP::byte *>(senha.c_str()), senha.length());

    // Converter o hash em uma string hexadecimal
    HexEncoder encoder;
    string senha_hash;
    encoder.Attach(new CryptoPP::StringSink(senha_hash));
    encoder.Put(digest, sizeof(digest));
    encoder.MessageEnd();

    // Inserir usuário no banco de dados
    const char *sql_insert =
        "INSERT INTO Usuarios (Nome, Email, Senha) VALUES (?, ?, ?);";

    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, sql_insert, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sqlite3_bind_text(stmt, 1, nome.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, email.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, senha_hash.c_str(), -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
    {
        cerr << "Erro ao inserir o usuário: " << sqlite3_errmsg(db) << endl;
    }
    else
    {
        cout << "Usuário criado com sucesso!" << endl;
    }

    sqlite3_finalize(stmt);
}

void Database::getUsers()
{
    const char *sql_select_all = "SELECT * FROM Usuarios;";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_select_all, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    cout << "Todos os usuários:\n";

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *name = sqlite3_column_text(stmt, 1);
        const unsigned char *email = sqlite3_column_text(stmt, 2);
        int admin = sqlite3_column_int(stmt, 4);

        cout << "ID: " << id << ", Nome: " << name << ", Email: " << email
             << ", Admin: " << (admin ? "Sim" : "Não") << endl;
    }

    sqlite3_finalize(stmt);
}

void Database::updateUser(int ID)
{
    const char *sql_update = "UPDATE Usuarios SET Admin = 1 WHERE ID = ?;";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_update, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sqlite3_bind_int(stmt, 1, ID);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
        cerr << "Erro ao atualizar o usuário: " << sqlite3_errmsg(db) << endl;

    else
        cout << "Usuário atualizado com sucesso!" << endl;

    sqlite3_finalize(stmt);
}

bool Database::login(const string &email, const string &senha, Users *users)
{
    const char *sql_select_user = "SELECT * FROM Usuarios WHERE Email = ?;";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_select_user, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, email.c_str(), -1, SQLITE_STATIC);

    // Verificar se o usuário com o email fornecido existe
    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        // Usuário encontrado
        const unsigned char *name_db = sqlite3_column_text(stmt, 1);
        const unsigned char *email_db = sqlite3_column_text(stmt, 2);
        const unsigned char *senha_db = sqlite3_column_text(stmt, 3);

        // Descriptografar a senha do banco de dados
        string senha_hash(reinterpret_cast<const char *>(senha_db));

        // Comparar as senhas
        SHA256 sha256;
        CryptoPP::byte digest[SHA256::DIGESTSIZE];
        sha256.CalculateDigest(digest, reinterpret_cast<const CryptoPP::byte *>(senha.c_str()), senha.length());

        HexEncoder encoder;
        string senha_fornecida_hash;
        encoder.Attach(new StringSink(senha_fornecida_hash));
        encoder.Put(digest, sizeof(digest));
        encoder.MessageEnd();
        if (senha_hash == senha_fornecida_hash)
        {
            cout << "Login realizado com sucesso!" << endl;
            cout << "Nome: " << name_db << ", Email: " << email_db << endl;
            users->setEmail(reinterpret_cast<const char *>(email_db));
            users->setName(reinterpret_cast<const char *>(name_db));
            sqlite3_finalize(stmt);
            return true;
        }
        else
        {
            cerr << "Senha incorreta." << endl;
            sqlite3_finalize(stmt);
            return false;
        }
    }
    else
    {
        cerr << "Usuário não encontrado." << endl;
        sqlite3_finalize(stmt);
        return false;
    }

    sqlite3_finalize(stmt);
}

int Database::getUserByEmail(const string &email)
{
    const char *sql_select_user = "SELECT * FROM Usuarios WHERE Email = ?;";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_select_user, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        return -1;
    }

    sqlite3_bind_text(stmt, 1, email.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt);
        return id;
    }
    else
    {
        cout << "Usuário não encontrado." << endl;
        sqlite3_finalize(stmt);
        return -1;
    }
}

int Database::getID(const string email)
{
    const char *sql_select_user = "SELECT ID FROM Usuarios WHERE Email = ?;";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_select_user, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        return -1;
    }

    sqlite3_bind_text(stmt, 1, email.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int id = sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt);
        return id;
    }
    else
    {
        cout << "Usuário não encontrado." << endl;
        sqlite3_finalize(stmt);
        return -1;
    }
}

// Employeers

void Database::updateEmployeerPosition(int ID, const string position)
{
    const char *sql_update = "UPDATE Usuarios SET Cargo = ? WHERE ID = ?;";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_update, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    sqlite3_bind_text(stmt, 1, position.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 2, ID);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE)
        cerr << "Erro ao atualizar o cargo do funcionário: " << sqlite3_errmsg(db) << endl;
    else
        cout << "Cargo do funcionário atualizado com sucesso!" << endl;

    sqlite3_finalize(stmt);
}

string Database::getUserType(const string &email)
{
    const char *sql_select_user = "SELECT Admin, Cargo FROM Usuarios WHERE Email = ?;";

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_select_user, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        sqlite3_finalize(stmt);
        return "Erro";
    }

    sqlite3_bind_text(stmt, 1, email.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int admin = sqlite3_column_int(stmt, 0);
        const unsigned char *cargo = sqlite3_column_text(stmt, 1);

        sqlite3_finalize(stmt);

        if (admin == 1)
        {
            return "admin";
        }
        else if (cargo != nullptr)
        {
            return reinterpret_cast<const char *>(cargo);
        }
        else
        {
            return "normal";
        }
    }
    else
    {
        cout << "Usuário não encontrado." << endl;
        sqlite3_finalize(stmt);
        return "Erro";
    }
}

void Database::addAudioBook(int bookID)
{
    const char *sql_update = "UPDATE Livros SET AudioBook = 1 WHERE ID = ?;";
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_update, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }
    sqlite3_bind_int(stmt, 1, bookID);
    rc = sqlite3_step(stmt);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao atualizar o livro: " << sqlite3_errmsg(db) << endl;
    }
    else
    {
        cout << "Livro atualizado com sucesso! " << endl;
    }
    sqlite3_finalize(stmt);
}

void Database::getAudioBook()
{
    const char *sql_select_AudioBook = "SELECT * FROM Livros WHERE AudioBook = 1;";
    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_select_AudioBook, -1, &stmt, nullptr); // Correção aqui
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }
    cout << "Livros com AudioBook: " << endl;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        int ID = sqlite3_column_int(stmt, 0);
        const unsigned char *title = sqlite3_column_text(stmt, 1);
        const unsigned char *author = sqlite3_column_text(stmt, 2);
        int borrowed = sqlite3_column_int(stmt, 3);
        const unsigned char *date = sqlite3_column_text(stmt, 4);
        cout << "ID: " << ID << ", Título: " << title << ", Autor: " << author << ", Emprestado: " << (borrowed ? "Sim" : "Não") << ", Data de lançamento: " << date << endl; // Correção na impressão
    }
    sqlite3_finalize(stmt);
}

void Database::getAudioBookByName(const string &bookName)
{
    if (bookName.empty())
    {
        cerr << "Erro: Nome do livro vazio." << endl;
        return;
    }

    const char *sql_select_multimedia = "SELECT * FROM Livros WHERE Titulo LIKE ? AND AudioBook = 1;"; // Correção aqui

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_select_multimedia, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    // String de busca com curingas para filtrar parte do título
    string searchName = "%" + bookName + "%";
    sqlite3_bind_text(stmt, 1, searchName.c_str(), -1, SQLITE_STATIC);

    bool found = false;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        found = true;
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *title = sqlite3_column_text(stmt, 1);
        const unsigned char *author = sqlite3_column_text(stmt, 2);
        int borrowed = sqlite3_column_int(stmt, 3);
        const unsigned char *date = sqlite3_column_text(stmt, 4);

        cout << "ID: " << id << ", Título: " << title << ", Autor: " << author << ", Emprestado: " << (borrowed ? "Sim" : "Não") << ", Data de Lançamento: " << date << endl;
    }

    sqlite3_finalize(stmt);

    if (!found)
    {
        cout << "Nenhum livro encontrado com o título contendo '" << bookName << "'." << endl;
    }
}

void Database::getAudioBookByAuthor(const string &bookAuthor)
{
    if (bookAuthor.empty())
    {
        cerr << "Erro: Nome do autor vazio." << endl; // Correção de mensagem de erro
        return;
    }

    const char *sql_select_multimedia = "SELECT * FROM Livros WHERE Autor LIKE ? AND AudioBook = 1;"; // Correção aqui

    sqlite3_stmt *stmt;
    int rc = sqlite3_prepare_v2(db, sql_select_multimedia, -1, &stmt, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao preparar a consulta: " << sqlite3_errmsg(db) << endl;
        return;
    }

    // String de busca com curingas para filtrar parte do título
    string searchName = "%" + bookAuthor + "%";
    sqlite3_bind_text(stmt, 1, searchName.c_str(), -1, SQLITE_STATIC);

    bool found = false;

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        found = true;
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *title = sqlite3_column_text(stmt, 1);
        const unsigned char *author = sqlite3_column_text(stmt, 2);
        int borrowed = sqlite3_column_int(stmt, 3);
        const unsigned char *date = sqlite3_column_text(stmt, 4);

        cout << "ID: " << id << ", Título: " << title << ", Autor: " << author << ", Emprestado: " << (borrowed ? "Sim" : "Não") << ", Data de Lançamento: " << date << endl;
    }

    sqlite3_finalize(stmt);

    if (!found)
    {
        cout << "Nenhum livro encontrado com o autor contendo '" << bookAuthor << "'." << endl; // Correção de mensagem de erro
    }
}
