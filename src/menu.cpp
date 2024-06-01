#include "menu.hpp"
#include "users.hpp"
#include <iostream>

using namespace std;

void printBoxedText(const string &text)
{
    string border = "╔════════════════════════════════════════╗";
    string padding = "║                                        ║";

    cout << border << endl;
    cout << "║ " << text;
    if (text.size() < 39)
    {
        for (size_t i = text.size(); i < 39; ++i)
            cout << " ";
    }
    cout << " ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
}

void printBoxedText2(const string &text)
{
    string border = "╔════════════════════════════════════════╗";
    string padding = "║                                        ║";

    cout << border << endl;
    cout << "║ " << text;
    if (text.size() < 38)
    {
        for (size_t i = text.size(); i < 38; ++i)
            cout << " ";
    }
    cout << " ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
}
void Menu::displayMainMenu_()
{
    printBoxedText2("Seja Bem-Vindo ao LibrarySoftware!");
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║ 1. Login                               ║" << endl;
    cout << "║ 2. Registrar                           ║" << endl;
    cout << "║ 3. Sair                                ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "Escolha uma opção: ";
}

void Menu::displayLoggedInAdminMenu_(Users *user)
{
    printBoxedText("Olá " + user->getName());
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║ 1. Cadastrar Livro                     ║" << endl;
    cout << "║ 2. Ver Lista de Livros                 ║" << endl;
    cout << "║ 3. Ver Lista de Livros Disponíveis     ║" << endl;
    cout << "║ 4. Ver Lista de Livros Alugados        ║" << endl;
    cout << "║ 5. Ver seus Livros Alugados            ║" << endl;
    cout << "║ 6. Ver histórico de aluguéis           ║" << endl;
    cout << "║ 7. Acessar histórias de usuários       ║" << endl;
    cout << "║ 8. Conceder permissão de administrador ║" << endl;
    cout << "║ 9. Cadastrar um funcionário            ║" << endl;
    cout << "║ 10. Alugar um Livro                    ║" << endl;
    cout << "║ 11. Acessar Audio Books                ║" << endl;
    cout << "║ 12. Logout                             ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "Escolha uma opção: ";
}

void Menu::displayLoggedInMenu_(Users *user)
{
    printBoxedText("Olá " + user->getName());
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║ 1. Ver Lista de Livros                 ║" << endl;
    cout << "║ 2. Ver Lista de Livros Disponíveis     ║" << endl;
    cout << "║ 3. Ver seus Livros Alugados            ║" << endl;
    cout << "║ 4. Ver histórico de aluguéis           ║" << endl;
    cout << "║ 5. Acessar histórias de usuários       ║" << endl;
    cout << "║ 6. Alugar um Livro                     ║" << endl;
    cout << "║ 7. Acessar Audio Books                 ║" << endl;
    cout << "║ 8. Logout                              ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "Escolha uma opção: ";
}

void Menu::displayEmployeerLoggedInMenu(Users *users)
{
    printBoxedText("Olá " + users->getName());
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║ 1. Ver Lista de Livros                 ║" << endl;
    cout << "║ 2. Ver Lista de Livros Disponíveis     ║" << endl;
    cout << "║ 3. Ver seus Livros Alugados            ║" << endl;
    cout << "║ 4. Ver histórico de aluguéis           ║" << endl;
    cout << "║ 5. Acessar histórias de usuários       ║" << endl;
    cout << "║ 6. Acessar Audio Books                 ║" << endl;
    cout << "║ 7. Logout                              ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "Escolha uma opção: ";
}

void Menu::login_()
{
    printBoxedText("Faça o login");
}

void Menu::registerUser_()
{
    printBoxedText("Faça o registro");
}

void Menu::createBooks_()
{
    printBoxedText2("Cadastro de Livro");
}

void Menu::closeSoftware_()
{
    printBoxedText("Saindo do software");
    exit(0);
}

void Menu::displayAllBooks_()
{
    printBoxedText2("Pesquisar Livros");
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║ 1. Pesquisar por nome                  ║" << endl;
    cout << "║ 2. Pesquisar por autor                 ║" << endl;
    cout << "║ 3. Voltar                              ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "Escolha uma opção: ";
}

void Menu::displayAdminAudioBooksMenu_()
{
    printBoxedText("Sessão Audio Livros");
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║ 1. Pesquisar por nome                  ║" << endl;
    cout << "║ 2. Pesquisar por autor                 ║" << endl;
    cout << "║ 3. Adicionar novo Audio Book           ║" << endl;
    cout << "║ 4. Voltar                              ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "Escolha uma opção: ";
}

void Menu::displayAudioBooksMenu_()
{
    printBoxedText("Sessão Audio Livros");
    cout << "╔════════════════════════════════════════╗" << endl;
    cout << "║ 1. Pesquisar por nome                  ║" << endl;
    cout << "║ 2. Pesquisar por autor                 ║" << endl;
    cout << "║ 3. Voltar                              ║" << endl;
    cout << "╚════════════════════════════════════════╝" << endl;
    cout << "Escolha uma opção: ";
}
