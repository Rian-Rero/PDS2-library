#include "employeers.hpp"

using namespace std;

Employeers::Employeers() : Users()
{
    position = "";
}
/**
 * @brief Construtor da classe Employeers.
 *
 * Inicializa um objeto Employeers com um cargo vazio.
 */

Employeers::~Employeers()
{
    delete dataBase;
}
/**
 * @brief Destrutor da classe Employeers.
 *
 * Limpa a memória alocada dinamicamente para o objeto Database.
 */

string Employeers::getPosition()
{
    return position;
}
/**
 * @brief Obtém o cargo do funcionário.
 *
 * @return string O cargo do funcionário.
 */

void Employeers::setPosition(string position)
{
    this->position = position;
}
/**
 * @brief Define o cargo do funcionário.
 *
 * @param position O cargo a ser definido.
 */

void Employeers::createEmployeer_()
{
    // Código da função createEmployeer_()
}
/**
 * @brief Cria um novo funcionário.
 *
 * Solicita informações ao usuário e cria um novo funcionário no banco de dados.
 */

void Employeers::updateEmployeerPosition_()
{
    // Código da função updateEmployeerPosition_()
}
/**
 * @brief Atualiza o cargo de um funcionário.
 *
 * Solicita o ID do funcionário e o novo cargo, e atualiza o cargo do funcionário
 * correspondente no banco de dados.
 */

void Employeers::displayInfo()
{

    Users::displayInfo();
    cout << "Cargo: " << getPosition() << endl;
}
