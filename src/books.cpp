#include <iostream>
#include <string>
#include <regex> // Validação de data
#include "books.hpp"

using namespace std;

/**
 * @brief Construtor padrão da classe Books.
 */
Books::Books()
{
    title = "";
    author = "";
    borrowed = false;
    date = "";
}

/**
 * @brief Cria um novo registro de livro no banco de dados.
 */
void Books::createBook_()
{
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
}

/**
 * @brief Busca e exibe todos os livros do banco de dados.
 */
void Books::getAllBooks_()
{
    try
    {
        dataBase->getAllBooks();
    }
    catch (const exception &e)
    {
        cerr << "Erro ao buscar os livros: " << e.what() << endl;
    }
}

/**
 * @brief Busca e exibe um livro específico pelo título.
 */
void Books::getBook_()
{
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
}

/**
 * @brief Busca e exibe todos os livros de um autor específico.
 */
void Books::getBookByAuthor_()
{
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
}

/**
 * @brief Busca e exibe todos os livros disponíveis ou emprestados.
 * @param borrowed Estado de empréstimo dos livros (true para emprestados, false para disponíveis).
 */
void Books::getAvailableBooks_(bool borrowed)
{
    try
    {
        dataBase->getAvailableBooks(borrowed);
    }
    catch (const exception &e)
    {
        cerr << "Erro ao buscar os livros disponíveis: " << e.what() << endl;
    }
}

/**
 * @brief Destrutor da classe Books.
 */
Books::~Books()
{
    delete dataBase;
}
