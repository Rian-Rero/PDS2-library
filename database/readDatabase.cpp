#include <iostream>
#include <iomanip>
#include <sqlite3.h>

using namespace std;

static int callback(void *data, int argc, char **argv, char **azColName)
{
    int i;
    cout << "Lendo dados..." << endl;

    // Imprimindo cabeçalhos das colunas
    for (i = 0; i < argc; i++)
    {
        cout << left << setw(15) << azColName[i] << "|";
    }
    cout << endl;

    // Imprimindo separador da tabela
    for (i = 0; i < argc; i++)
    {
        cout << "---------------+";
    }
    cout << endl;

    // Imprimindo dados
    for (i = 0; i < argc; i++)
    {
        cout << left << setw(15) << (argv[i] ? argv[i] : "NULL") << "|";
    }
    cout << endl
         << endl;

    return 0;
}

int main(int argc, char *argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_open("./database/LibraryDevelopmentDB.db", &db);

    if (rc)
    {
        cerr << "Erro ao abrir o banco de dados: " << sqlite3_errmsg(db) << endl;
        return (0);
    }
    else
    {
        cout << "Banco de dados aberto com sucesso." << endl;
    }

    const char *livros_sql = "SELECT * FROM Livros";
    const char *usuarios_sql = "SELECT * FROM Usuarios";

    rc = sqlite3_exec(db, livros_sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        cerr << "Erro na consulta SQL de Livros: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "Consulta SQL de Livros executada com sucesso." << endl;
    }

    rc = sqlite3_exec(db, usuarios_sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        cerr << "Erro na consulta SQL de Usuarios: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "Consulta SQL de Usuarios executada com sucesso." << endl;
    }

    sqlite3_close(db);
    return 0;
}
