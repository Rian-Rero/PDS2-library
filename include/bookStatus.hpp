#ifndef BOOKSTATUS_H
#define BOOKSTATUS_H

#include "databaseConfig.hpp"
#include "dataBase.hpp"

class BookStatus
{

private:
    DataBaseConfig dataBaseName;
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());

public:
    BookStatus();
    void rentBook_(int userID);
    void returnBook_(int userID);
    void getBorrowedHistory_(int userID);
    void getCurrentBorrowedBooks_(int userID);
    ~BookStatus();
};

#endif // BOOKSTATUS_H