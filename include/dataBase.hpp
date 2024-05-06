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

    // Books

    void createBook(const string &title, const string &author, bool borrowed, const string &date);
    void getAllBooks();
    void getBook(const string &name);
    void getBookByAuthor(const string &author);
    void getAvailableBooks(bool borrowed);

    // Users

    void createUser(const string &name, const string &email, const string &password);
    bool login(const string &email, const string &password);

private:
    sqlite3 *db;
};

#endif // DATABASE_H
