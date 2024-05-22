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
    int admin;

public:
    // Constructor
    Users();

    // Getters

    void getAllUsers_();
    void getUser_();
    string getName();
    string getEmail();
    int isAdmin();

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