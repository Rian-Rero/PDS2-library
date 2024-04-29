
#include <iostream>
#include "menu.hpp"
#include "books.hpp"

using namespace std;

int main()
{
    cout << "Seja Bem-Vindo ao LibrarySoftware" << endl;

    // Variables

    Menu *menu = new Menu();
    Books *books = new Books();
    int choice;

    // Main Menu

    do
    {
        menu->displayMainMenu_();
        cin >> choice;
        switch (choice)
        {
        case 1:
            menu->login_();
            int loggedChoice;
            do
            {
                menu->displayLoggedInMenu_();
                cin >> loggedChoice;
                switch (loggedChoice)
                {
                case 1:
                    menu->createBooks_();
                    books->createBook_();
                    break;
                case 2:
                    cout << "Deslogando..." << endl;
                    break;
                default:
                    cout << "Opção inválida. Por favor, escolha uma opção válida." << endl;
                    break;
                }
            } while (loggedChoice != 2);
            break;
        case 2:
            menu->registerUser_();
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
    return 0;
}
