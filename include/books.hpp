#ifndef BOOKS_H
#define BOOKS_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Books
{
private:
    string title;
    string author;
    bool borrowed;
    string date;

public:
    // Constructor

    Books();

    // Getters

    void getAllBooks_();
    void getBook_();
    void getBookByAuthor_();
    void getAvailableBooks_(bool borrowed);
    void getTitle_();
    void getAuthor_();
    void isBorrowed_();
    void getDate_();

    // Setters

    void createBook_();
};

#endif // BOOKS_H