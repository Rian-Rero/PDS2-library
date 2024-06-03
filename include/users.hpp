#ifndef USERS_H
#define USERS_H

#include <string>
#include <iostream>
#include "databaseConfig.hpp"

using namespace std;

/**
 * @brief Classe que representa usuários do sistema.
 *
 */
class Users
{
private:
    string name;                 /**< Nome do usuário. */
    string email;                /**< Email do usuário. */
    string password;             /**< Senha do usuário. */
    int admin;                   /**< Indica se o usuário é um administrador ou não. */
    DataBaseConfig dataBaseName; /**< Nome do banco de dados. */

public:
    // Constructor
    /**
     * @brief Construtor da classe Users.
     *
     */
    Users();

    // Getters

    /**
     * @brief Obtém o nome do usuário.
     *
     * @return string Nome do usuário.
     */
    string getName();

    /**
     * @brief Obtém o email do usuário.
     *
     * @return string Email do usuário.
     */
    string getEmail();

    /**
     * @brief Verifica se o usuário é um administrador.
     *
     * @return int Retorna 1 se o usuário for um administrador, senão retorna 0.
     */
    int isAdmin();

    // Setters

    /**
     * @brief Define o nome do usuário.
     *
     * @param name Nome do usuário.
     */
    void setName(string name);

    /**
     * @brief Define o email do usuário.
     *
     * @param email Email do usuário.
     */
    void setEmail(string email);

    /**
     * @brief Define se o usuário é um administrador.
     *
     * @param admin Indica se o usuário é um administrador (1) ou não (0).
     */
    void setAdmin(int admin);

    // Métodos

    /**
     * @brief Cria um novo usuário.
     *
     */
    void createUser_();

    /**
     * @brief Realiza o login do usuário.
     *
     * @param users Ponteiro para o objeto Users.
     * @return bool Retorna verdadeiro se o login for bem-sucedido, senão retorna falso.
     */
    bool login_(Users *users);

    /**
     * @brief Obtém todos os usuários do sistema.
     *
     */
    void getAllUsers_();

    /**
     * @brief Atualiza as informações de um usuário.
     *
     */
    void updateUser_();

    /**
     * @brief Exclui um usuário do sistema.
     *
     */
    void deleteUser_();

    /**
     * @brief Obtém o tipo de usuário com base no email.
     *
     * @param email Email do usuário.
     * @return string Retorna o tipo de usuário.
     */
    string getUserType_(const string &email);

    /**
     * @brief Obtém o ID do usuário com base no email.
     *
     * @param email Email do usuário.
     * @return int Retorna o ID do usuário.
     */
    int getID_(string email);

    // Destructor
    /**
     * @brief Destrutor da classe Users.
     *
     */
    ~Users();
};
#endif // USERS_H
