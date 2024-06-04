#ifndef DATABASE_H
#define DATABASE_H

#include "users.hpp"
#include <sqlite3.h>
#include <string>

using namespace std;

/**
 * @brief Classe para gerenciar a conexão e operações com o banco de dados.
 */
class Database
{
public:
    /**
     * @brief Construtor que inicializa a conexão com o banco de dados.
     * @param filename Nome do arquivo do banco de dados.
     */
    Database(const string &filename);

    /**
     * @brief Destrutor que fecha a conexão com o banco de dados.
     */
    ~Database();

    // Livros

    /**
     * @brief Cria um novo livro no banco de dados.
     * @param title Título do livro.
     * @param author Autor do livro.
     * @param borrowed Status de empréstimo do livro.
     * @param date Data de adição do livro.
     */
    void createBook(const string &title, const string &author, bool borrowed, const string &date);

    /**
     * @brief Obtém todos os livros do banco de dados.
     */
    void getAllBooks();

    /**
     * @brief Obtém um livro pelo nome.
     * @param name Nome do livro.
     */
    void getBook(const string &name);

    /**
     * @brief Obtém o nome de um livro pelo ID.
     * @param ID ID do livro.
     * @return Nome do livro.
     */
    string getBookName(int ID);

    /**
     * @brief Obtém livros por autor.
     * @param author Autor dos livros.
     */
    void getBookByAuthor(const string &author);

    /**
     * @brief Obtém livros disponíveis para empréstimo.
     * @param borrowed Status de empréstimo (false para disponíveis).
     */
    void getAvailableBooks(bool borrowed);

    /**
     * @brief Realiza o empréstimo de um livro.
     * @param bookID ID do livro.
     * @param userID ID do usuário.
     */
    void rentBook(int bookID, int userID);

    /**
     * @brief Realiza a devolução de um livro.
     * @param bookID ID do livro.
     * @param userID ID do usuário.
     */
    void returnBook(int bookID, int userID);

    /**
     * @brief Obtém o histórico de empréstimos de um usuário.
     * @param userID ID do usuário.
     */
    void getBorrowedHistory(int userID);

    /**
     * @brief Obtém os livros atualmente emprestados por um usuário.
     * @param userID ID do usuário.
     */
    void getCurrentBorrowedBooks(int userID);

    // Usuários

    /**
     * @brief Cria um novo usuário no banco de dados.
     * @param name Nome do usuário.
     * @param email Email do usuário.
     * @param password Senha do usuário.
     */
    void createUser(const string &name, const string &email, const string &password);

    /**
     * @brief Realiza o login de um usuário.
     * @param email Email do usuário.
     * @param password Senha do usuário.
     * @param users Ponteiro para o objeto Users.
     * @return true se o login for bem-sucedido, false caso contrário.
     */
    bool login(const string &email, const string &password, Users *users);

    /**
     * @brief Obtém todos os usuários do banco de dados.
     */
    void getUsers();

    /**
     * @brief Atualiza as informações de um usuário.
     * @param ID ID do usuário.
     */
    void updateUser(int ID);

    /**
     * @brief Obtém o ID de um usuário pelo email.
     * @param email Email do usuário.
     * @return ID do usuário.
     */
    int getUserByEmail(const string &email);

    /**
     * @brief Obtém o tipo de um usuário pelo email.
     * @param email Email do usuário.
     * @return Tipo do usuário.
     */
    string getUserType(const string &email);

    /**
     * @brief Obtém o ID de um usuário pelo email.
     * @param email Email do usuário.
     * @return ID do usuário.
     */
    int getID(const string email);

    // Funcionários

    /**
     * @brief Atualiza a posição de um funcionário.
     * @param ID ID do funcionário.
     * @param position Nova posição do funcionário.
     */
    void updateEmployeerPosition(int ID, const string position);

    // Audiobook

    /**
     * @brief Adiciona um audiobook no banco de dados.
     * @param bookID ID do livro associado ao audiobook.
     */
    void addAudioBook(int bookID);

    /**
     * @brief Obtém todos os audiobooks do banco de dados.
     */
    void getAudioBook();

    /**
     * @brief Obtém um audiobook pelo nome do livro.
     * @param bookName Nome do livro.
     */
    void getAudioBookByName(const string &bookName);

    /**
     * @brief Obtém audiobooks pelo autor do livro.
     * @param bookAuthor Autor do livro.
     */
    void getAudioBookByAuthor(const string &bookAuthor);

private:
    sqlite3 *db; ///< Ponteiro para a conexão com o banco de dados.
};

#endif // DATABASE_H
