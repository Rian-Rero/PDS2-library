#ifndef APPLICATION_H
#define APPLICATION_H

#include "menu.hpp"
#include "books.hpp"
#include "users.hpp"
#include "employeers.hpp"

class Application
{
public:
    Application();
    void run();

private:
    Menu *menu = new Menu();
    Books *books = new Books();
    Users *users = new Users();
    Employeers *employeers = new Employeers();
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

#endif // APPLICATION_H
