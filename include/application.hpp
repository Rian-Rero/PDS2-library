#ifndef APPLICATION_H
#define APPLICATION_H

#include "menu.hpp"
#include "books.hpp"
#include "users.hpp"
#include "employeers.hpp"
#include "bookStatus.hpp"
#include "audioBook.hpp"

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
    AudioBook *audioBook = new AudioBook();
    bool isLogged;
    int choice;
    int loggedChoice;
    int audioBookChoice;

    void displayMainMenu();
    void handleLogin();
    void handleLoggedInMenu();
    void handleCreateBooks();
    void handleViewBooks();
    void handleUserRegistration();
    void handleAudioBook();
    void handleAdminAudioBook();
};

#endif // APPLICATION_H
