#ifndef BOOKSTATUS_H
#define BOOKSTATUS_H

#include "books.hpp"

class BookStatus : public Books
{

public:
    BookStatus();
    void rentBook_(int userID);
    void returnBook_(int userID);
    void getBorrowedHistory_(int userID);
    void getCurrentBorrowedBooks_(int userID);
    ~BookStatus();
};

#endif // BOOKSTATUS_H