#include <iostream>
#include <sqlite3.h>

using namespace std;
static int callback(void *data, int argc, char **argv, char **azColName)
{
    int i;
    cout << "Lendo dados..." << endl;
    for (i = 0; i < argc; i++)
    {
        cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << endl;
    }
    cout << endl;
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

    const char *sql = "SELECT * FROM Livros";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        cerr << "Erro na consulta SQL: " << zErrMsg << endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        cout << "Consulta SQL executada realizada sucesso." << endl;
    }

    sqlite3_close(db);
    return 0;
}
