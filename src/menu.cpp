#include "menu.hpp"
#include <iostream>

using namespace std;
void Menu::displayMainMenu_()
{
    cout << "Seja Bem-Vindo ao LibrarySoftware" << endl;
    cout << "1. Login" << endl;
    cout << "2. Registrar" << endl;
    cout << "3. Sair" << endl;
    cout << "Escolha uma opção: ";
}
void Menu::displayLoggedInMenu_()
{
    cout << "Olá Usuário" << endl;
    cout << "1. Cadastrar Livro" << endl;
    cout << "2. Logout" << endl;
    cout << "Escolha uma opção: ";
}

void Menu::login_()
{
    cout << "Faça o login" << endl;
}

void Menu::registerUser_()
{
    cout << "Faça o registro" << endl;
}

void Menu::createBooks_()
{
    cout << "Cadastro de Livro" << endl;
}

void Menu::closeSoftware_()
{
    cout << "Saindo do software" << endl;
    exit(0);
}
