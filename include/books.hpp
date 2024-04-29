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

    string getTitle() const;
    string getAuthor() const;
    bool isBorrowed() const;
    string getDate() const;

    // Setters

    void createBook_();
};

#endif // BOOKS_H