#include "checkAudio.hpp"
#include "dataBase.hpp"
#include "books.hpp"
#include <iostream>

bool checkAudio(const std::string &bookTitle) {
    Database *dataBase = new Database("./database/LibraryDevelopmentDB.db");
    bool hasAudio = false;

    try {
        Books book = dataBase->getBook(bookTitle);
        hasAudio = book.hasAudio();
    } catch (const std::exception &e) {
        std::cerr << "Erro ao verificar a versão em áudio: " << e.what() << std::endl;
    }

    delete dataBase;
    return hasAudio;
}