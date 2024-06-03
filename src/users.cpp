#include <string>
#include <iostream>

using namespace std;

Users::Users()
{
    name = "";
    email = "";
    password = "";
};

Users::~Users()
{
    delete dataBase;
};

void Users::createUser_()
{

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

    return loginSuccessful;
}

void Users::getAllUsers_()
{

    try
    {
        dataBase->getUsers();
    }
    catch (const exception &e)
    {
        cerr << "Erro ao buscar os usuários: " << e.what() << endl;
    }
}

void Users::updateUser_()
{

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
}

string Users::getUserType_(const string &email)
{

    string position = dataBase->getUserType(email);

    return position;
}

int Users::getID_(string email)
{

    int ID = dataBase->getID(email.c_str());

    return ID;
}