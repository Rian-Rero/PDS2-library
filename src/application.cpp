#include <iostream>
#include <limits>
#include "application.hpp"
#include "UserHistory.hpp"

using namespace std;

Application::Application() : isLogged(false), choice(0), loggedChoice(0) {}

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

void Application::handleLogin()
{
    menu->login_();
    isLogged = users->login_(users);
    if (isLogged)
    {
        handleLoggedInMenu();
    }
}

void Application::handleLoggedInMenu()
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
        break;
    case 2:
        handleViewBooks();
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
        // Adicione as operações necessárias para a opção 5
        break;
    case 6:
        // Adicione as operações necessárias para a opção 6
        break;
    case 7:
        UserHistory();
        handleLoggedInMenu();
        break;
    case 8:
        users->getAllUsers_();
        users->updateUser_();
        break;
    case 9:
        employeers->createEmployeer_();
        break;
    case 10:
        cout << "Deslogando..." << endl;
        isLogged = false;
        break;
    default:
        cout << "Opção inválida. Por favor, escolha uma opção válida." << endl;
        break;
    }
}

void Application::handleCreateBooks()
{
    menu->createBooks_();
    books->createBook_();
}

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
        default:
            cout << "Opção inválida. Por favor, escolha uma opção válida." << endl;
            break;
        }
    } while (allBooksChoice != 3);
}

void Application::handleUserRegistration()
{
    menu->registerUser_();
    users->createUser_();
}
