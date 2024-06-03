#include "bookStatus.hpp"

BookStatus::BookStatus() {}

BookStatus::~BookStatus()
{
    delete dataBase;
}

void BookStatus::rentBook_(int userID)
{

    int bookID;
    cout << "Digite o ID do livro que deseja alugar" << endl;
    cin >> bookID;

    dataBase->rentBook(bookID, userID);
}
void BookStatus::returnBook_(int userID)
{

    int bookID;
    cout << "Digite o ID do livro que deseja devolver" << endl;
    cin >> bookID;

    dataBase->returnBook(bookID, userID);
}

void BookStatus::getBorrowedHistory_(int userID)
{

    dataBase->getBorrowedHistory(userID);
}
void BookStatus::getCurrentBorrowedBooks_(int userID)
{

    dataBase->getCurrentBorrowedBooks(userID);
}
