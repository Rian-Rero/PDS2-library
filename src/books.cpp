
#include <iostream>
#include <string>
#include <regex> // Validação de data
#include "dataBase.hpp"
#include "books.hpp"
#include "databaseConfig.hpp"

using namespace std;

Books::Books()
{
    title = "";
    author = "";
    borrowed = false;
    date = "";
};

void Books::createBook_()
{
    DataBaseConfig dataBaseName;
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());

    string title, author, dateStr;
    bool borrowed = false;

    cin.ignore();
    cout << "Digite o título do livro: ";
    getline(cin, title);

    cout << "Digite o nome do autor: ";
    getline(cin, author);

    string borrowedInput;
    bool validBorrowedInput = false;
    while (!validBorrowedInput)
    {
        cout << "O livro está emprestado? (1 para sim, 0 para não): ";
        getline(cin, borrowedInput);
        if (borrowedInput == "1" || borrowedInput == "0")
        {
            borrowed = (borrowedInput == "1");
            validBorrowedInput = true;
        }
        else
        {
            cout << "Entrada inválida. Por favor, digite 1 para sim ou 0 para não." << endl;
        }
    }

    regex dateRegex("\\d{2}/\\d{2}/\\d{4}");
    while (true)
    {
        cout << "Digite a data de cadastro (DD/MM/AAAA): ";
        getline(cin, dateStr);
        if (regex_match(dateStr, dateRegex))
        {
            break;
        }
        else
        {
            cout << "Formato de data inválido. Por favor, use o formato DD/MM/AAAA." << endl;
        }
    }

    try
    {
        dataBase->createBook(title, author, borrowed, dateStr);
    }
    catch (const exception &e)
    {
        cerr << "Erro ao criar o livro: " << e.what() << endl;
    }

    delete dataBase;
}
void Books::getAllBooks_()
{
    DataBaseConfig dataBaseName;
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());

    try
    {
        dataBase->getAllBooks();
    }
    catch (const exception &e)
    {
        cerr << "Erro ao buscar os livros: " << e.what() << endl;
    }
    delete dataBase;
}

void Books::getBook_()
{
    DataBaseConfig dataBaseName;
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());
    string name;
    cin.ignore();
    cout << "Digite o nome do livro: ";
    getline(cin, name);

    try
    {
        dataBase->getBook(name);
    }
    catch (const exception &e)
    {
        cerr << "Erro ao buscar o livro: " << e.what() << endl;
    }
    delete dataBase;
}

void Books::getBookByAuthor_()
{
    DataBaseConfig dataBaseName;
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());
    string author;
    cin.ignore();
    cout << "Digite o nome do autor: ";
    getline(cin, author);

    try
    {
        dataBase->getBookByAuthor(author);
    }
    catch (const exception &e)
    {
        cerr << "Erro ao buscar o livro: " << e.what() << endl;
    }
    delete dataBase;
}

void Books::getAvailableBooks_(bool borrowed)
{
    DataBaseConfig dataBaseName;
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());

    try
    {
        dataBase->getAvailableBooks(borrowed);
    }
    catch (const exception &e)
    {
        cerr << "Erro ao buscar os livros disponíveis: " << e.what() << endl;
    }
    delete dataBase;
}

Books::~Books(){

};