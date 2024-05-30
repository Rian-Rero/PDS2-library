#include "bookStatus.hpp"
#include "dataBase.hpp"
#include "databaseConfig.hpp"

BookStatus::BookStatus()
{
}

BookStatus::~BookStatus()
{
}

void BookStatus::rentBook_(int userID)
{
    DataBaseConfig dataBaseName;
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());
    int bookID;
    cout << "Digite o ID do livro que deseja alugar" << endl;
    cin >> bookID;

    dataBase->rentBook(bookID, userID);

    delete dataBase;
}
void BookStatus::returnBook_(int userID)
{

    DataBaseConfig dataBaseName;
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());
    int bookID;
    cout << "Digite o ID do livro que deseja devolver" << endl;
    cin >> bookID;

    dataBase->returnBook(bookID, userID);

    delete dataBase;
}

void BookStatus::getBorrowedHistory_(int userID)
{

    DataBaseConfig dataBaseName;
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());
    dataBase->getBorrowedHistory(userID);
    delete dataBase;
}
void BookStatus::getCurrentBorrowedBooks_(int userID)
{
    DataBaseConfig dataBaseName;
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());
    dataBase->getCurrentBorrowedBooks(userID);
    delete dataBase;
}
