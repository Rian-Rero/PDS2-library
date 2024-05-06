
#include <iostream>
#include <limits>
#include "menu.hpp"
#include "books.hpp"
#include "users.hpp"

using namespace std;

int main()
{
    // Variables

    Menu *menu = new Menu();
    Books *books = new Books();
    Users *users = new Users();
    int choice;

    // Main Menu

    do
    {
        menu->displayMainMenu_();
        if (!(cin >> choice))
        {
            cout << "Entrada inválida. Por favor, insira um número." << endl;
            cin.clear();                                         // Limpa o estado de falha de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpa o buffer de entrada
            continue;                                            // Reinicia o loop para pedir outra entrada válida
        }
        switch (choice)
        {
        case 1:
            menu->login_();
            int loggedChoice;
            do
            {
                users->login_(users);
                menu->displayLoggedInAdminMenu_(users);
                if (!(cin >> loggedChoice))
                {
                    cout << "Entrada inválida. Por favor, insira um número." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                switch (loggedChoice)
                {
                case 1:
                    menu->createBooks_();
                    books->createBook_();
                    break;
                case 2:
                    books->getAllBooks_();
                    int allBooksChoice;
                    do
                    {
                        menu->displayAllBooks_();
                        if (!(cin >> allBooksChoice))
                        {
                            cout << "Entrada inválida. Por favor, insira um número." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                        }
                        switch (allBooksChoice)
                        {
                        case 1:
                            books->getBook_();
                            break;
                        case 2:
                            books->getBookByAuthor_();
                            break;
                        case 3:
                            break;
                        }
                    } while (allBooksChoice != 3);
                    break;
                case 3:
                    books->getAvailableBooks_(false);
                    break;
                case 4:
                    books->getAvailableBooks_(true);
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    menu->HistoriasUsuarios_();
                    break;
                case 8:
                    cout << "Deslogando..." << endl;
                    break;
                default:
                    cout << "Opção inválida. Por favor, escolha uma opção válida." << endl;
                    break;
                }
            } while (loggedChoice != 8);
            break;
        case 2:
            menu->registerUser_();
            users->createUser_();
            break;
        case 3:
            menu->closeSoftware_();
            break;
        default:
            cout << "Opção inválida. Por favor, escolha uma opção válida." << endl;
            break;
        }
    } while (choice != 3);

    delete menu;  // Desalocando a memória do Menu
    delete books; // Desalocando a memória dos livros
    delete users; // Desalocando a memória dos usuários
    return 0;
}
