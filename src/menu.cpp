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
void Menu::displayLoggedInAdminMenu_()
{
    cout << "Olá Administrador" << endl;
    cout << "1. Cadastrar Livro" << endl;
    cout << "2. Ver Lista de Livros" << endl;
    cout << "3. Ver Lista de Livros Disponíveis" << endl;
    cout << "4. Ver Lista de Livros Alugados" << endl;
    cout << "5. Ver seus Livros Alugados" << endl;
    cout << "6. Ver histórico de aluguéis" << endl;
    cout << "7. Logout" << endl;
    cout << "Escolha uma opção: ";
}
void Menu::displayLoggedInMenu_()
{
    cout << "Olá Usuário" << endl;
    cout << "1. Ver Lista de Livros" << endl;
    cout << "2. Ver Lista de Livros Disponíveis" << endl;
    cout << "3. Ver seus Livros Alugados" << endl;
    cout << "4. Ver histórico de aluguéis" << endl;
    cout << "5. Logout" << endl;
    cout << "Escolha uma opção: ";
};
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

void Menu::displayAllBooks_()
{
    cout << "1. Pesquisar por nome" << endl;
    cout << "2. Pesquisar por autor" << endl;
    cout << "3. Voltar" << endl;
    cout << "Escolha uma opção: ";
}
