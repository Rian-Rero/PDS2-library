#include <iostream>
#include "UserHistory.hpp"

using namespace std;

UserHistory::UserHistory()
{
    cout << "Cadastro de Usuários:" << endl;
    cout << "Como um novo membro da comunidade da biblioteca, desejo poder criar uma conta no sistema da biblioteca para acessar os serviços oferecidos, como pesquisar e reservar livros." << endl;
    cout << "Cenário Teste:" << endl;
    cout << "- O usuário deve ser capaz de conseguir registrar seu dados e ter um perfil." << endl;
    cout << "- O usuário deve conseguir ver quais livros estão emprestados por ele naquele momento." << endl;
    cout << "- O usuário deve conseguir ver o histórico de livros emprestados." << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "Cadastro de Livros:" << endl;
    cout << "Como um administrador da biblioteca, desejo poder cadastrar novos livros no sistema para que eles estejam disponíveis para empréstimo. Eu gostaria de inserir informações como título, autor, gênero e número de cópias disponíveis." << endl;
    cout << "Cenário Teste:" << endl;
    cout << "- Apenas o administrador deve ser possível adicionar novos livros ao catálogo do sistema." << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "Pesquisa de Livros:" << endl;
    cout << "Como um usuário da biblioteca, desejo poder pesquisar livros por título, autor ou gênero para encontrar rapidamente os materiais que estou interessado em ler. Eu gostaria que os resultados da pesquisa mostrassem informações detalhadas sobre cada livro, como disponibilidade e localização na biblioteca." << endl;
    cout << "Cenário Teste:" << endl;
    cout << "- O usuário deve ser capaz de pesquisar no catálogo da loja , por título." << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "Reserva de Livros:" << endl;
    cout << "Como um usuário da biblioteca, desejo poder reservar livros que não estão atualmente disponíveis para empréstimo. Eu gostaria de receber uma notificação quando o livro estiver disponível para retirada e de ter um prazo para buscá-lo antes que a reserva seja cancelada." << endl;
    cout << "Cenário Teste:" << endl;
    cout << "- Um usuário após registrado deve poder reservar um livro" << endl;

}