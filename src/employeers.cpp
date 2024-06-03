#include "employeers.hpp"
#include <iostream>
#include <string>

using namespace std;

Employeers::Employeers() : Users()
{
    position = "";
}

Employeers::~Employeers() : Users()
{
    delete dataBase;
}

string Employeers::getPosition()
{
    return position;
}

void Employeers::setPosition(string position)
{
    this->position = position;
}

void Employeers::createEmployeer_()
{

    cin.ignore();
    string name, email, password, position;
    cout << "Digite o nome do funcionário: ";
    getline(cin, name);

    cout << "Digite o email do funcionário: ";
    getline(cin, email);

    cout << "Digite a senha do funcionário: ";
    getline(cin, password);

    cout << "Digite o cargo do funcionário: ";
    getline(cin, position);

    try
    {
        dataBase->createUser(name, email, password);
        // Now update the cargo for the newly created user
        this->setName(name);
        this->setEmail(email);
        this->setPosition(position);
        int userID = dataBase->getUserByEmail(email);
        dataBase->updateEmployeerPosition(userID, position);
    }
    catch (const exception &e)
    {
        cerr << "Erro ao criar o funcionário: " << e.what() << endl;
    }
}

void Employeers::updateEmployeerPosition_()
{

    cin.ignore();
    int ID;
    string position;
    cout << "Digite o ID do funcionário que deseja atualizar o cargo: ";
    cin >> ID;
    cin.ignore();
    cout << "Digite o novo cargo do funcionário: ";
    getline(cin, position);

    try
    {
        dataBase->updateEmployeerPosition(ID, position);
    }
    catch (const exception &e)
    {
        cerr << "Erro ao atualizar o cargo do funcionário: " << e.what() << endl;
    }
}
