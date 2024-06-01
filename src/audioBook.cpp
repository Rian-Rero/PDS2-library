#include "audioBook.hpp"
#include <iostream>
#include <string>

using namespace std;

AudioBook::AudioBook(){
    hasAudioBook=0;
}

AudioBook::~AudioBook(){
    delete dataBase;
}

void AudioBook::addAudioBook_(){
    int bookID;
    cout<<"Digite o ID do livro que deseja adicionar o audiobook: "<<endl;
    cin>>bookID;
    dataBase->addAudioBook(bookID);
}

void AudioBook::getAudioBook_(){
    dataBase->getAudioBook();
}

void AudioBook::getAudioBookByName_(){
    string bookName;
    cout<<"Digite o nome do livro que deseja buscar: "<<endl;
    cin.ignore();
    getline(cin, bookName);
    dataBase->getAudioBookByName(bookName);
}

void AudioBook::getAudioBookByAuthor_(){
    string bookAuthor;
    cout<<"Digite o nome do autor que deseja buscar: "<<endl;
    cin.ignore();
    getline(cin, bookAuthor);
    dataBase->getAudioBookByAuthor(bookAuthor);
}