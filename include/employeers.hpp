#ifndef EMPLOYEERS_H
#define EMPLOYEERS_H

#include "users.hpp"
#include "databaseConfig.hpp"
#include "dataBase.hpp"

class Employeers : public Users
{
private:
    string position;
    DataBaseConfig dataBaseName;
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());

public:
    // Constructor
    Employeers();

    // Destructor
    ~Employeers();

    // Getters
    string getPosition();

    // Setters
    void setPosition(string position);

    // Methods
    void createEmployeer_();
    void updateEmployeerPosition_();
};

#endif // EMPLOYEERS_H
