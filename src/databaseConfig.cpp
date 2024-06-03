#include "databaseConfig.hpp"

using namespace std;

/**
 * @brief Retorna o nome do arquivo do banco de dados.
 *
 * Este método retorna o nome do arquivo do banco de dados.
 *
 * @return O nome do arquivo do banco de dados.
 */
const string DataBaseConfig::getDataBaseFileName()
{
    string fileName = "./database/LibraryDevelopmentDB3.db";
    return fileName;
}
