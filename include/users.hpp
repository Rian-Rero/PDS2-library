#ifndef USERS_H
#define USERS_H

#include <string>
#include <iostream>

using namespace std;

class Users
{
private:
    string name;
    string email;
    string password;

public:
    // Constructor
    Users();

    // Getters

    void getAllUsers_();
    void getUser_();
    string getName();
    string getEmail();

    // Setters

    void createUser_();
    void updateUser_();
    void deleteUser_();
    void login_();
    void setName(string name);
    void setEmail(string email);

    // Destructor
};
#endif // USERS_H