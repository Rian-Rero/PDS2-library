#ifndef BOOKS_H
#define BOOKS_H

#include <string>
#include <iostream>
#include "databaseConfig.hpp"
#include "dataBase.hpp"

using namespace std;

/**
 * @class Books
 * @brief Classe que representa um livro e suas operações no banco de dados.
 */
class Books
{
private:
    string title;                                                          ///< Título do livro
    string author;                                                         ///< Autor do livro
    bool borrowed;                                                         ///< Estado de empréstimo do livro
    string date;                                                           ///< Data de cadastro do livro
    DataBaseConfig dataBaseName;                                           ///< Configuração do banco de dados
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName()); ///< Ponteiro para o objeto Database

public:
    /**
     * @brief Construtor padrão da classe Books.
     */
    Books();

    /**
     * @brief Busca e exibe todos os livros do banco de dados.
     */
    void getAllBooks_();

    /**
     * @brief Busca e exibe um livro específico pelo título.
     */
    void getBook_();

    /**
     * @brief Busca e exibe todos os livros de um autor específico.
     */
    void getBookByAuthor_();

    /**
     * @brief Busca e exibe todos os livros disponíveis ou emprestados.
     * @param borrowed Estado de empréstimo dos livros (true para emprestados, false para disponíveis).
     */
    void getAvailableBooks_(bool borrowed);

    /**
     * @brief Cria um novo registro de livro no banco de dados.
     */
    void createBook_();

    /**
     * @brief Destrutor da classe Books.
     */
    ~Books();
};

#endif // BOOKS_H
