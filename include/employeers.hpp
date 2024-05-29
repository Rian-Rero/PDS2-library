#ifndef EMPLOYEERS_H
#define EMPLOYEERS_H

#include "users.hpp"

class Employeers : public Users
{
private:
    string position;

public:
    // Constructor
    Employeers();

    // Getters
    string getPosition();

    // Setters
    void setPosition(string position);

    // Methods
    void createEmployeer_();
    void updateEmployeerPosition_();
};

#endif // EMPLOYEERS_H
