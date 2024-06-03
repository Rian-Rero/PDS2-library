#ifndef USERS_H
#define USERS_H

#include <string>
#include <iostream>
#include "databaseConfig.hpp"
#include "dataBase.hpp"

using namespace std;

class Users
{
private:
    string name;
    string email;
    string password;
    int admin;
    DataBaseConfig dataBaseName;
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());

public:
    // Constructor
    Users();

    // Getters

    void getAllUsers_();
    void getUser_();
    string getName();
    string getEmail();
    int isAdmin();
    string getUserType_(const string &email);
    int getID_(string email);

    // Setters

    void createUser_();
    void updateUser_();
    void deleteUser_();
    bool login_(Users *users);
    void setName(string name);
    void setEmail(string email);
    void setAdmin(int admin);

    // Destructor
    ~Users();
};
#endif // USERS_H