#ifndef DATABASE_CONFIG_H
#define DATABASE_CONFIG_H

#include <string>

using namespace std;

/**
 * @brief Classe para configurações do banco de dados.
 */
class DataBaseConfig
{
public:
    /**
     * @brief Retorna o nome do arquivo do banco de dados.
     * @return O nome do arquivo do banco de dados.
     */
    static const string getDataBaseFileName();
};

#endif // DATABASE_CONFIG_H
