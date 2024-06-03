#include "audioBook.hpp"
#include <iostream>
#include <string>

using namespace std;

/**
 * @brief Construtor padrão da classe AudioBook
 */
AudioBook::AudioBook()
{
    hasAudioBook = 0;
}

/**
 * @brief Destrutor da classe AudioBook
 */
AudioBook::~AudioBook()
{
    delete dataBase;
}

/**
 * @brief Adiciona um audiobook ao banco de dados
 *
 * Solicita ao usuário o ID do livro para o qual deseja adicionar um audiobook e o adiciona ao banco de dados.
 */
void AudioBook::addAudioBook_()
{
    int bookID;
    cout << "Digite o ID do livro que deseja adicionar o audiobook: " << endl;
    cin >> bookID;
    dataBase->addAudioBook(bookID);
}

/**
 * @brief Obtém todos os audiobooks do banco de dados
 */
void AudioBook::getAudioBook_()
{
    dataBase->getAudioBook();
}

/**
 * @brief Obtém um audiobook pelo nome do livro
 *
 * Solicita ao usuário o nome do livro e busca no banco de dados.
 */
void AudioBook::getAudioBookByName_()
{
    string bookName;
    cout << "Digite o nome do livro que deseja buscar: " << endl;
    cin.ignore();
    getline(cin, bookName);
    dataBase->getAudioBookByName(bookName);
}

/**
 * @brief Obtém um audiobook pelo nome do autor
 *
 * Solicita ao usuário o nome do autor e busca no banco de dados.
 */
void AudioBook::getAudioBookByAuthor_()
{
    string bookAuthor;
    cout << "Digite o nome do autor que deseja buscar: " << endl;
    cin.ignore();
    getline(cin, bookAuthor);
    dataBase->getAudioBookByAuthor(bookAuthor);
}
