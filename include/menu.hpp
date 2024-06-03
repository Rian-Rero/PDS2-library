#ifndef MENU_H
#define MENU_H

#include "users.hpp"
#include <string>

/**
 * @brief Classe para gerenciar o menu do sistema.
 */
class Menu
{
public:
    /**
     * @brief Exibe o menu principal para o usuário não autenticado.
     */
    void displayMainMenu_();

    /**
     * @brief Exibe o menu para o usuário autenticado como administrador.
     *
     * @param user O usuário autenticado.
     */
    void displayLoggedInAdminMenu_(Users *user);

    /**
     * @brief Exibe o menu para o usuário autenticado.
     *
     * @param user O usuário autenticado.
     */
    void displayLoggedInMenu_(Users *user);

    /**
     * @brief Exibe o menu para o funcionário autenticado.
     *
     * @param users O usuário autenticado como funcionário.
     */
    void displayEmployeerLoggedInMenu(Users *users);

    /**
     * @brief Realiza o processo de login do usuário.
     */
    void login_();

    /**
     * @brief Realiza o processo de registro de um novo usuário.
     */
    void registerUser_();

    /**
     * @brief Exibe o menu para adicionar novos livros ao sistema.
     */
    void createBooks_();

    /**
     * @brief Fecha o software.
     */
    void closeSoftware_();

    /**
     * @brief Exibe todos os livros disponíveis no sistema.
     */
    void displayAllBooks_();

    /**
     * @brief Exibe o histórico de usuários.
     */
    void HistoriasUsuarios_();

    /**
     * @brief Exibe o menu de administração dos áudio livros.
     */
    void displayAdminAudioBooksMenu_();

    /**
     * @brief Exibe o menu dos áudio livros.
     */
    void displayAudioBooksMenu_();
};

#endif // MENU_H
