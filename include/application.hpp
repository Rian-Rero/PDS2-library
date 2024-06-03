#ifndef APPLICATION_H
#define APPLICATION_H

#include "menu.hpp"
#include "books.hpp"
#include "users.hpp"
#include "employeers.hpp"
#include "bookStatus.hpp"
#include "audioBook.hpp"

/**
 * @brief A classe Application representa a aplicação principal.
 */
class Application
{
public:
    /**
     * @brief Constrói um novo objeto Application.
     */
    Application();

    /**
     * @brief Inicia a aplicação.
     */
    void run();

    /**
     * @brief Destrói o objeto Application.
     */
    ~Application();

private:
    Menu *menu = new Menu();                   ///< Ponteiro para o objeto Menu
    Books *books = new Books();                ///< Ponteiro para o objeto Books
    Users *users = new Users();                ///< Ponteiro para o objeto Users
    Employeers *employeers = new Employeers(); ///< Ponteiro para o objeto Employeers
    BookStatus *bookStatus = new BookStatus(); ///< Ponteiro para o objeto BookStatus
    AudioBook *audioBook = new AudioBook();    ///< Ponteiro para o objeto AudioBook
    bool isLogged;                             ///< Indica se o usuário está logado
    int choice;                                ///< Escolha do usuário no menu principal
    int loggedChoice;                          ///< Escolha do usuário quando logado
    int audioBookChoice;                       ///< Escolha do usuário no menu de audiolivros

    /**
     * @brief Exibe o menu principal.
     */
    void displayMainMenu();

    /**
     * @brief Lida com o processo de login.
     */
    void handleLogin();

    /**
     * @brief Lida com o menu para usuários logados.
     */
    void handleLoggedInMenu();

    /**
     * @brief Lida com a criação de livros.
     */
    void handleCreateBooks();

    /**
     * @brief Lida com a visualização de livros.
     */
    void handleViewBooks();

    /**
     * @brief Lida com o registro de novos usuários.
     */
    void handleUserRegistration();

    /**
     * @brief Lida com o menu de audiolivros.
     */
    void handleAudioBook();

    /**
     * @brief Lida com o menu de audiolivros para administradores.
     */
    void handleAdminAudioBook();
};

#endif // APPLICATION_H
