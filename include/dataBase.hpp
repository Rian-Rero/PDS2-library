#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>

using namespace std;
class Database
{
public:
    Database(const string &filename);
    ~Database();

    void createBook(const string &title, const string &author, bool borrowed, const string &date);

private:
    sqlite3 *db;
};

#endif // DATABASE_H
