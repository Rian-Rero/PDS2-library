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

Users::~Users(){};

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

int Users::isAdmin()
{
    return admin;
}

void Users::setName(string name)
{
    this->name = name;
}
void Users::setEmail(string email)
{
    this->email = email;
}

void Users::setAdmin(int admin)
{
    this->admin = admin;
}

bool Users::login_(Users *users)
{
    Database *dataBase = new Database("./database/LibraryDevelopmentDB.db");
    cin.ignore();
    string email, password;
    cout << "Digite o email do usuário: ";
    getline(cin, email);

    cout << "Digite a senha do usuário: ";
    getline(cin, password);

    bool loginSuccessful = false;
    try
    {
        if (dataBase->login(email, password, users))
            loginSuccessful = true;
        else
            loginSuccessful = false;
    }
    catch (const exception &e)
    {
        cerr << "Erro ao logar o usuário: " << e.what() << endl;
    }

    delete dataBase;
    return loginSuccessful;
}

void Users::getAllUsers_()
{
    Database *dataBase = new Database("./database/LibraryDevelopmentDB.db");
    try
    {
        dataBase->getUsers();
    }
    catch (const exception &e)
    {
        cerr << "Erro ao buscar os usuários: " << e.what() << endl;
    }

    delete dataBase;
}

void Users::updateUser_()
{
    Database *dataBase = new Database("./database/LibraryDevelopmentDB.db");
    cin.ignore();
    int ID;
    cout << "Digite o ID do usuário que deseja tornar administrador: ";
    cin >> ID;
    try
    {
        dataBase->updateUser(ID);
    }
    catch (const exception &e)
    {
        cerr << "Erro ao tornar o usuário um administrador: " << e.what() << endl;
    }

    delete dataBase;
}