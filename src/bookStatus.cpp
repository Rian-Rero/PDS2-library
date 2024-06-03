#include "bookStatus.hpp"

/**
 * @brief Construtor da classe BookStatus.
 */
BookStatus::BookStatus() {}

/**
 * @brief Destrutor da classe BookStatus.
 */
BookStatus::~BookStatus()
{
    delete dataBase;
}

/**
 * @brief Aluga um livro para um usuário.
 * @param userID ID do usuário que deseja alugar o livro.
 */
void BookStatus::rentBook_(int userID)
{
    int bookID;
    std::cout << "Digite o ID do livro que deseja alugar" << std::endl;
    std::cin >> bookID;

    dataBase->rentBook(bookID, userID);
}

/**
 * @brief Devolve um livro alugado por um usuário.
 * @param userID ID do usuário que deseja devolver o livro.
 */
void BookStatus::returnBook_(int userID)
{
    int bookID;
    std::cout << "Digite o ID do livro que deseja devolver" << std::endl;
    std::cin >> bookID;

    dataBase->returnBook(bookID, userID);
}

/**
 * @brief Obtém o histórico de livros alugados por um usuário.
 * @param userID ID do usuário cujo histórico será obtido.
 */
void BookStatus::getBorrowedHistory_(int userID)
{
    dataBase->getBorrowedHistory(userID);
}

/**
 * @brief Obtém os livros atualmente alugados por um usuário.
 * @param userID ID do usuário cujos livros alugados serão obtidos.
 */
void BookStatus::getCurrentBorrowedBooks_(int userID)
{
    dataBase->getCurrentBorrowedBooks(userID);
}
