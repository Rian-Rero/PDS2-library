#ifndef MENU_H
#define MENU_H

#include "users.hpp"
#include <string>

class Menu
{
public:
    void displayMainMenu_();
    void displayLoggedInAdminMenu_(Users *user);
    void displayLoggedInMenu_(Users *user);
    void displayEmployeerLoggedInMenu(Users *users);
    void login_();
    void registerUser_();
    void createBooks_();
    void closeSoftware_();
    void displayAllBooks_();
    void HistoriasUsuarios_();
    void displayAudioBooksMenu_();
};

#endif // MENU_H
