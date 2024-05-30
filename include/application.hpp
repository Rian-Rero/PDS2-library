#ifndef APPLICATION_H
#define APPLICATION_H

#include "menu.hpp"
#include "books.hpp"
#include "users.hpp"
#include "employeers.hpp"
#include "bookStatus.hpp"

class Application
{
public:
    Application();
    void run();
    ~Application();

private:
    Menu *menu = new Menu();
    Books *books = new Books();
    Users *users = new Users();
    Employeers *employeers = new Employeers();
    BookStatus *bookStatus = new BookStatus();
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
