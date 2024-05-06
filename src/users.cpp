#include <string>
#include <iostream>
#include "users.hpp"
#include "dataBase.hpp"

using namespace std;

Users::Users()
{
    name = "";
    email = "";
    password = "";
};

void Users::createUser_()
{
    Database *dataBase = new Database("./database/LibraryDevelopmentDB.db");
    cin.ignore();
    string name, email, password;
    cout << "Digite o nome do usuário: ";
    getline(cin, name);

    cout << "Digite o email do usuário: ";
    getline(cin, email);

    cout << "Digite a senha do usuário: ";
    getline(cin, password);

    try
    {
        dataBase->createUser(name, email, password);
    }
    catch (const exception &e)
    {
        cerr << "Erro ao criar o usuário: " << e.what() << endl;
    }

    delete dataBase;
}

string Users::getEmail()
{
    return email;
}

string Users::getName()
{
    return name;
}

void Users::setName(string name)
{
    this->name = name;
}
void Users::setEmail(string email)
{
    this->email = email;
}

void Users::login_(Users *users)
{
    Database *dataBase = new Database("./database/LibraryDevelopmentDB.db");
    cin.ignore();
    string email, password;
    cout << "Digite o email do usuário: ";
    getline(cin, email);

    cout << "Digite a senha do usuário: ";
    getline(cin, password);

    try
    {
        dataBase->login(email, password, users);
    }
    catch (const exception &e)
    {
        cerr << "Erro ao logar o usuário: " << e.what() << endl;
    }

    delete dataBase;
}
