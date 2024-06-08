#ifndef EMPLOYEERS_H
#define EMPLOYEERS_H

#include "users.hpp"
#include "databaseConfig.hpp"
#include "dataBase.hpp"

using namespace std;

/**
 * @brief Classe que representa funcionários.
 *
 * Esta classe herda da classe Users e adiciona funcionalidades específicas
 * para manipulação de funcionários.
 */
class Employeers : public Users
{
private:
    string position;                                                       ///< Cargo do funcionário.
    DataBaseConfig dataBaseName;                                           ///< Configurações do banco de dados.
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName()); ///< Instância do banco de dados.

public:
    // Constructor
    /**
     * @brief Construtor da classe Employeers.
     *
     */
    Employeers();

    // Destructor
    /**
     * @brief Destrutor da classe Employeers.
     *
     */
    ~Employeers();

    // Getters
    /**
     * @brief Obtém o cargo do funcionário.
     *
     * @return string O cargo do funcionário.
     */
    string getPosition();

    // Setters
    /**
     * @brief Define o cargo do funcionário.
     *
     * @param position O cargo a ser definido.
     */
    void setPosition(string position);

    virtual void displayInfo() override;

    // Methods
    /**
     * @brief Cria um novo funcionário.
     *
     * Solicita informações ao usuário e cria um novo funcionário no banco de dados.
     */
    void createEmployeer_();

    /**
     * @brief Atualiza o cargo de um funcionário.
     *
     * Solicita o ID do funcionário e o novo cargo, e atualiza o cargo do funcionário
     * correspondente no banco de dados.
     */
    void updateEmployeerPosition_();
};

#endif // EMPLOYEERS_H
