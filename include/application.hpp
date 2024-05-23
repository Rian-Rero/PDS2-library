#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "menu.hpp"
#include "books.hpp"
#include "users.hpp"

class Application
{
public:
    Application();
    void run();

private:
    Menu *menu = new Menu();
    Books *books = new Books();
    Users *users = new Users();
    bool isLogged;
    int choice;
    int loggedChoice;

    void displayMainMenu();
    void handleLogin();
    void handleLoggedInMenu();
    void handleCreateBooks();
    void handleViewBooks();
    void handleUserRegistration();
};

#endif // APPLICATION_HPP
