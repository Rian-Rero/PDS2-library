#include "menu.hpp"
#include <iostream>

using namespace std;
void Menu::displayMainMenu_()
{
    cout << "Seja Bem-Vindo ao LibrarySoftware" << endl;
    cout << "1. Login" << endl;
    cout << "2. Registrar" << endl;
    cout << "3. Sair" << endl;
    cout << "Escolha uma opção: ";
}
void Menu::displayLoggedInAdminMenu_()
{
    cout << "Olá Administrador" << endl;
    cout << "1. Cadastrar Livro" << endl;
    cout << "2. Ver Lista de Livros" << endl;
    cout << "3. Ver Lista de Livros Disponíveis" << endl;
    cout << "4. Ver Lista de Livros Alugados" << endl;
    cout << "5. Ver seus Livros Alugados" << endl;
    cout << "6. Ver histórico de aluguéis" << endl;
    cout << "7. Acesssar histórias de usuários" << endl;
    cout << "8. Logout" << endl;
    cout << "Escolha uma opção: ";
}
void Menu::displayLoggedInMenu_()
{
    cout << "Olá Usuário" << endl;
    cout << "1. Ver Lista de Livros" << endl;
    cout << "2. Ver Lista de Livros Disponíveis" << endl;
    cout << "3. Ver seus Livros Alugados" << endl;
    cout << "4. Ver histórico de aluguéis" << endl;
    cout << "5. Acesssar histórias de usuários" << endl;
    cout << "6. Logout" << endl;
    cout << "Escolha uma opção: ";
};
void Menu::login_()
{
    cout << "Faça o login" << endl;
}

void Menu::registerUser_()
{
    cout << "Faça o registro" << endl;
}

void Menu::createBooks_()
{
    cout << "Cadastro de Livro" << endl;
}

void Menu::closeSoftware_()
{
    cout << "Saindo do software" << endl;
    exit(0);
}

void Menu::displayAllBooks_()
{
    cout << "1. Pesquisar por nome" << endl;
    cout << "2. Pesquisar por autor" << endl;
    cout << "3. Voltar" << endl;
    cout << "Escolha uma opção: ";
}

void Menu::HistoriasUsuarios_()
{
    cout <<"Cadastro de Usuários:"<<endl;
    cout<<"Como um novo membro da comunidade da biblioteca, desejo poder criar uma conta no sistema da biblioteca para acessar os serviços oferecidos, como pesquisar e reservar livros."<<endl;
    cout<<"Cenário Teste:"<<endl;
    cout<<"- O usuário deve ser capaz de conseguir registrar seu dados e ter um perfil."<<endl;
    cout<<"- O usuário deve conseguir ver quais livros estão emprestados por ele naquele momento."<<endl;
    cout<<"- O usuário deve conseguir ver o histórico de livros emprestados."<<endl;
    cout<<"------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Cadastro de Livros:"<<endl;
    cout<<"Como um administrador da biblioteca, desejo poder cadastrar novos livros no sistema para que eles estejam disponíveis para empréstimo. Eu gostaria de inserir informações como título, autor, gênero e número de cópias disponíveis."<<endl;
    cout<<"Cenário Teste:"<<endl;
    cout<<"- Apenas o administrador deve ser possível adicionar novos livros ao catálogo do sistema."<<endl;
    cout<<"------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Pesquisa de Livros:"<<endl;
    cout<<"Como um usuário da biblioteca, desejo poder pesquisar livros por título, autor ou gênero para encontrar rapidamente os materiais que estou interessado em ler. Eu gostaria que os resultados da pesquisa mostrassem informações detalhadas sobre cada livro, como disponibilidade e localização na biblioteca."<<endl;
    cout<<"Cenário Teste:"<<endl;
    cout<<"- O usuário deve ser capaz de pesquisar no catálogo da loja , por título."<<endl;
    cout<<"------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Reserva de Livros:"<<endl;
    cout<<"Como um usuário da biblioteca, desejo poder reservar livros que não estão atualmente disponíveis para empréstimo. Eu gostaria de receber uma notificação quando o livro estiver disponível para retirada e de ter um prazo para buscá-lo antes que a reserva seja cancelada."<<endl;
    cout<<"Cenário Teste:"<<endl;
    cout<<"- Um usuário após registrado deve poder reservar um livro"<< endl;
}
