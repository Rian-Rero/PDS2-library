#ifndef BOOKS_H
#define BOOKS_H

#include <string>
#include <iostream>
#include "databaseConfig.hpp"
#include "dataBase.hpp"

using namespace std;

class Books
{
private:
    string title;
    string author;
    bool borrowed;
    string date;
    DataBaseConfig dataBaseName;
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());

public:
    // Constructor

    Books();

    // Getters

    void getAllBooks_();
    void getBook_();
    void getBookByAuthor_();
    void getAvailableBooks_(bool borrowed);

    // Setters

    void createBook_();

    // Destructor

    ~Books();
};

#endif // BOOKS_H