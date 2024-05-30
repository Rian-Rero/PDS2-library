#include "menu.hpp"
#include "users.hpp"
#include <iostream>

using namespace std;

void Menu::displayMainMenu_()
{
    cout << "==============================" << endl;
    cout << "  Seja Bem-Vindo ao LibrarySoftware" << endl;
    cout << "==============================" << endl;
    cout << "1. Login" << endl;
    cout << "2. Registrar" << endl;
    cout << "3. Sair" << endl;
    cout << "==============================" << endl;
    cout << "Escolha uma opção: ";
}

void Menu::displayLoggedInAdminMenu_(Users *user)
{

    cout << "==============================" << endl;
    cout << "         Olá " << user->getName() << endl;
    cout << "==============================" << endl;
    cout << "1. Cadastrar Livro" << endl;
    cout << "2. Ver Lista de Livros" << endl;
    cout << "3. Ver Lista de Livros Disponíveis" << endl;
    cout << "4. Ver Lista de Livros Alugados" << endl;
    cout << "5. Ver seus Livros Alugados" << endl;
    cout << "6. Ver histórico de aluguéis" << endl;
    cout << "7. Acesssar histórias de usuários" << endl;
    cout << "8. Conceder permissão de administrador" << endl;
    cout << "9. Cadastrar um funcionário" << endl;
    cout << "10. Logout" << endl;
    cout << "==============================" << endl;
    cout << "Escolha uma opção: ";
}

void Menu::displayLoggedInMenu_(Users *user)
{
    cout << "==============================" << endl;
    cout << "            Olá " << user->getName() << endl;
    cout << "==============================" << endl;
    cout << "1. Ver Lista de Livros" << endl;
    cout << "2. Ver Lista de Livros Disponíveis" << endl;
    cout << "3. Ver seus Livros Alugados" << endl;
    cout << "4. Ver histórico de aluguéis" << endl;
    cout << "5. Acesssar histórias de usuários" << endl;
    cout << "6. Logout" << endl;
    cout << "==============================" << endl;
    cout << "Escolha uma opção: ";
}

void Menu::displayEmployeerLoggedInMenu(Users *users)
{
    cout << "==============================" << endl;
    cout << "         Olá " << users->getName() << endl;
    cout << "==============================" << endl;
    cout << "1. Ver Lista de Livros" << endl;
    cout << "2. Ver Lista de Livros Disponíveis" << endl;
    cout << "3. Ver seus Livros Alugados" << endl;
    cout << "4. Ver histórico de aluguéis" << endl;
    cout << "5. Acesssar histórias de usuários" << endl;
    cout << "6. Logout" << endl;
    cout << "==============================" << endl;
    cout << "Escolha uma opção: ";
}

void Menu::login_()
{
    cout << "==============================" << endl;
    cout << "          Faça o login" << endl;
    cout << "==============================" << endl;
}

void Menu::registerUser_()
{
    cout << "==============================" << endl;
    cout << "         Faça o registro" << endl;
    cout << "==============================" << endl;
}

void Menu::createBooks_()
{
    cout << "==============================" << endl;
    cout << "      Cadastro de Livro" << endl;
    cout << "==============================" << endl;
}

void Menu::closeSoftware_()
{
    cout << "==============================" << endl;
    cout << "    Saindo do software" << endl;
    cout << "==============================" << endl;
    exit(0);
}

void Menu::displayAllBooks_()
{
    cout << "==============================" << endl;
    cout << "         Pesquisar Livros" << endl;
    cout << "==============================" << endl;
    cout << "1. Pesquisar por nome" << endl;
    cout << "2. Pesquisar por autor" << endl;
    cout << "3. Voltar" << endl;
    cout << "==============================" << endl;
    cout << "Escolha uma opção: ";
}
