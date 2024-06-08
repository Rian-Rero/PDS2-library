#include <iostream>
#include <limits>
#include "application.hpp"
#include "UserHistory.hpp"

using namespace std;

/**
 * @brief Constrói um novo objeto Application.
 */
Application::Application() : isLogged(false), choice(0), loggedChoice(0) {}

/**
 * @brief Destrói o objeto Application.
 */
Application::~Application()
{
    delete menu;
    delete books;
    delete users;
    delete employeers;
    delete bookStatus;
    delete audioBook;
}

/**
 * @brief Inicia a aplicação.
 */
void Application::run()
{
    while (choice != 3)
    {
        displayMainMenu();
        if (choice == 1)
        {
            handleLogin();
        }
        else if (choice == 2)
        {
            handleUserRegistration();
        }
        else if (choice == 3)
        {
            menu->closeSoftware_();
        }
        else
        {
            cout << "Opção inválida. Por favor, escolha uma opção válida." << endl;
        }
    }
}

/**
 * @brief Exibe o menu principal.
 */
void Application::displayMainMenu()
{
    menu->displayMainMenu_();
    if (!(cin >> choice))
    {
        cout << "Entrada inválida. Por favor, insira um número." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        choice = 0;
    }
}

/**
 * @brief Lida com o processo de login.
 */
void Application::handleLogin()
{
    menu->login_();
    isLogged = users->login_(users);
    if (isLogged)
    {
        handleLoggedInMenu();
    }
}

/**
 * @brief Lida com o menu para usuários logados.
 */
void Application::handleLoggedInMenu()
{
    string position = users->getUserType_(users->getEmail());
    if (position.compare("admin") == 0)
    {
        menu->displayLoggedInAdminMenu_(users);
        if (!(cin >> loggedChoice))
        {
            cout << "Entrada inválida. Por favor, insira um número." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            loggedChoice = 0;
        }

        switch (loggedChoice)
        {
        case 1:
            handleCreateBooks();
            handleLoggedInMenu();
            break;
        case 2:
            handleViewBooks();
            handleLoggedInMenu();
            break;
        case 3:
            books->getAvailableBooks_(false);
            handleLoggedInMenu();
            break;
        case 4:
            books->getAvailableBooks_(true);
            handleLoggedInMenu();
            break;
        case 5:
            bookStatus->getCurrentBorrowedBooks_(users->getID_(users->getEmail()));
            handleLoggedInMenu();
            break;
        case 6:
            bookStatus->getBorrowedHistory_(users->getID_(users->getEmail()));
            handleLoggedInMenu();
            break;
        case 7:
            UserHistory();
            handleLoggedInMenu();
            break;
        case 8:
            users->getAllUsers_();
            users->updateUser_();
            handleLoggedInMenu();
            break;
        case 9:
            employeers->createEmployeer_();
            handleLoggedInMenu();
            break;
        case 10:
            users->displayInfo();
            handleLoggedInMenu();
            break;
        case 11:
            books->getAllBooks_();
            bookStatus->rentBook_(users->getID_(users->getEmail()));
            handleLoggedInMenu();
            break;
        case 12:
            audioBook->getAudioBook_();
            handleAdminAudioBook();
            break;
        case 13:
            cout << "Deslogando..." << endl;
            isLogged = false;
            break;
        default:
            cout << "Opção inválida. Por favor, escolha uma opção válida." << endl;
            break;
        }
    }
    else if (position.compare("normal") == 0)
    {
        menu->displayLoggedInMenu_(users);
        if (!(cin >> loggedChoice))
        {
            cout << "Entrada inválida. Por favor, insira um número." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            loggedChoice = 0;
        }
        switch (loggedChoice)
        {
        case 1:
            handleViewBooks();
            break;
        case 2:
            books->getAvailableBooks_(false);
            handleLoggedInMenu();
            break;
        case 3:
            bookStatus->getCurrentBorrowedBooks_(users->getID_(users->getEmail()));
            handleLoggedInMenu();
            break;
        case 4:
            bookStatus->getBorrowedHistory_(users->getID_(users->getEmail()));
            break;
        case 5:
            UserHistory();
            handleLoggedInMenu();
            break;
        case 6:
            books->getAllBooks_();
            bookStatus->rentBook_(users->getID_(users->getEmail()));
            handleLoggedInMenu();
            break;
        case 7:
            audioBook->getAudioBook_();
            handleAudioBook();
            break;
        case 8:
            users->displayInfo();
            handleLoggedInMenu();
            break;
        case 9:
            cout << "Deslogando..." << endl;
            isLogged = false;
            break;
        default:
            cout << "Opção inválida. Por favor, escolha uma opção válida." << endl;
            break;
        }
    }
    else
    {
        menu->displayEmployeerLoggedInMenu(users);
        if (!(cin >> loggedChoice))
        {
            cout << "Entrada inválida. Por favor, insira um número." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            loggedChoice = 0;
        }
        switch (loggedChoice)
        {
        case 1:
            handleViewBooks();
            handleLoggedInMenu();
            break;
        case 2:
            books->getAvailableBooks_(false);
            handleLoggedInMenu();
            break;
        case 3:
            bookStatus->getCurrentBorrowedBooks_(users->getID_(users->getEmail()));
            handleLoggedInMenu();
            break;
        case 4:
            bookStatus->getBorrowedHistory_(users->getID_(users->getEmail()));
            handleLoggedInMenu();
            break;
        case 5:
            UserHistory();
            handleLoggedInMenu();
            break;
        case 6:
            audioBook->getAudioBook_();
            handleAdminAudioBook();
            break;
        case 7:
            cout << "Deslogando..." << endl;
            isLogged = false;
            break;
        default:
            cout << "Opção inválida. Por favor, escolha uma opção válida." << endl;
            break;
        }
    }
}

/**
 * @brief Lida com a criação de livros.
 */
void Application::handleCreateBooks()
{
    menu->createBooks_();
    books->createBook_();
}

/**
 * @brief Lida com a visualização de livros.
 */
void Application::handleViewBooks()
{
    int allBooksChoice;
    books->getAllBooks_();
    do
    {
        menu->displayAllBooks_();
        if (!(cin >> allBooksChoice))
        {
            cout << "Entrada inválida. Por favor, insira um número." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            allBooksChoice = 0;
        }

        switch (allBooksChoice)
        {
        case 1:
            books->getBook_();
            break;
        case 2:
            books->getBookByAuthor_();
            break;
        case 3:
            handleLoggedInMenu();
            break;
        default:
            cout << "Opção inválida. Por favor, escolha uma opção válida." << endl;
            break;
        }
    } while (allBooksChoice != 3);
}

/**
 * @brief Lida com o registro de novos usuários.
 */
void Application::handleUserRegistration()
{
    menu->registerUser_();
    users->createUser_();
}

/**
 * @brief Lida com o menu de audiolivros.
 */
void Application::handleAudioBook()
{
    do
    {
        menu->displayAudioBooksMenu_();
        if (!(cin >> audioBookChoice))
        {
            cout << "Entrada inválida. Por favor, insira um número." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            audioBookChoice = 0;
        }
        switch (audioBookChoice)
        {
        case 1:
            audioBook->getAudioBookByName_();
            break;
        case 2:
            audioBook->getAudioBookByAuthor_();
            break;
        case 3:
            handleLoggedInMenu();
            break;
        default:
            cout << "Opção inválida. Por favor, escolha uma opção válida." << endl;
            break;
        }
    } while (audioBookChoice != 3);
}

/**
 * @brief Lida com o menu de audiolivros para administradores.
 */
void Application::handleAdminAudioBook()
{
    do
    {
        menu->displayAdminAudioBooksMenu_();
        if (!(cin >> audioBookChoice))
        {
            cout << "Entrada inválida. Por favor, insira um número." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            audioBookChoice = 0;
        }
        switch (audioBookChoice)
        {
        case 1:
            audioBook->getAudioBookByName_();
            break;
        case 2:
            audioBook->getAudioBookByAuthor_();
            break;
        case 3:
            audioBook->addAudioBook_();
            break;
        case 4:
            handleLoggedInMenu();
            break;
        default:
            cout << "Opção inválida. Por favor, escolha uma opção válida." << endl;
            break;
        }
    } while (audioBookChoice != 4);
}
