#include "dataBase.hpp"
#include <iostream>

using namespace std;

Database::Database(const string &filename)
{
    int rc = sqlite3_open(filename.c_str(), &db);
    if (rc)
    {
        cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(db) << endl;
        throw runtime_error("Erro ao abrir o banco de dados");
    }
    const char *sql_create_table =
        "CREATE TABLE IF NOT EXISTS Livros ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
        "Titulo TEXT NOT NULL,"
        "Autor TEXT NOT NULL,"
        "Emprestado INTEGER NOT NULL,"
        "DataCadastro TEXT NOT NULL"
        ");";

    rc = sqlite3_exec(db, sql_create_table, nullptr, nullptr, nullptr);
    if (rc != SQLITE_OK)
    {
        cerr << "Erro ao criar a tabela Livros: " << sqlite3_errmsg(db) << endl;
        throw runtime_error("Erro ao criar a tabela Livros");
    }
}

Database::~Database()
{
    sqlite3_close(db);
}

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
}
