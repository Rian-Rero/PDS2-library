#include <iostream>

#include "multimedia.hpp"

using namespace std;

Multimedia::Multimedia()
{
    hasAudioBook = 0;
}

Multimedia::~Multimedia()
{
    delete dataBase;
}

void Multimedia::addMultimedia_()
{

    int bookID;
    cout << "Digite o ID do livro que deseja adicionar multimídia" << endl;
    cin >> bookID;
    dataBase->addMultimedia(bookID);
}
void Multimedia::getMultimedia_()
{

    dataBase->getMultimedia();
}
void Multimedia::getMultimediaByName_()
{

    string bookName;
    cout << "Digite o nome do livro que deseja buscar multimídia" << endl;
    cin.ignore();
    getline(cin, bookName);
    dataBase->getMultimediaByName(bookName);
}
