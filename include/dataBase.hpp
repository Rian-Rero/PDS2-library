#ifndef DATABASE_H
#define DATABASE_H

#include "users.hpp"
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
    void rentBook(int bookID, int userID);
    void returnBook(int bookID, int userID);
    void getBorrowedHistory(int userID);
    void getCurrentBorrowedBooks(int userID);

    // Users

    void createUser(const string &name, const string &email, const string &password);
    bool login(const string &email, const string &password, Users *users);
    void getUsers();
    void updateUser(int ID);
    int getUserByEmail(const string &email);
    string getUserType(const string &email);
    int getID(const string email);

    // Employeers

    void updateEmployeerPosition(int ID, const string position);

    // AudioBook

    void addAudioBook(int bookID);
    void getAudioBook();
    void getAudioBookByName(const string &bookName);
    void getAudioBookByAuthor(const string &bookAuthor);

private:
    sqlite3 *db;
};

#endif // DATABASE_H
