#ifndef BOOKSTATUS_H
#define BOOKSTATUS_H

#include "databaseConfig.hpp"
#include "dataBase.hpp"

/**
 * @brief Classe que gerencia o status de livros para usuários.
 */
class BookStatus
{

private:
    DataBaseConfig dataBaseName;
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());

public:
    /**
     * @brief Construtor da classe BookStatus.
     */
    BookStatus();

    /**
     * @brief Aluga um livro para um usuário.
     * @param userID ID do usuário que deseja alugar o livro.
     */
    void rentBook_(int userID);

    /**
     * @brief Devolve um livro alugado por um usuário.
     * @param userID ID do usuário que deseja devolver o livro.
     */
    void returnBook_(int userID);

    /**
     * @brief Obtém o histórico de livros alugados por um usuário.
     * @param userID ID do usuário cujo histórico será obtido.
     */
    void getBorrowedHistory_(int userID);

    /**
     * @brief Obtém os livros atualmente alugados por um usuário.
     * @param userID ID do usuário cujos livros alugados serão obtidos.
     */
    void getCurrentBorrowedBooks_(int userID);

    /**
     * @brief Destrutor da classe BookStatus.
     */
    ~BookStatus();
};

#endif // BOOKSTATUS_H
