#include "dataBase.hpp"
#include <iostream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/sha.h>     // Para SHA-256
#include <cryptopp/hex.h>     // Para codificação hexadecimal
#include <cryptopp/filters.h> // Para Crypto++ filters
#include <sstream>            // Adicionando inclusão para stringstream

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
        "Titulo TEXT NOT NULL"
        "Autor TEXT NOT NULL,"
        "Emprestado INTEGER NOT NULL,"
        "DataCadastro TEXT NOT NULL"
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
        "Senha TEXT NOT NULL"
        ");";

    rc = sqlite3_exec(db, sql_create_table_usuarios, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao criar a tabela Usuarios: " << sqlite3_errmsg(db) << endl;
        throw runtime_error("Erro ao criar a tabela Usuarios");
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
    string senha_hash;
    StringSource(senha, true, new HashFilter(sha256, new HexEncoder(new StringSink(senha_hash))));

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