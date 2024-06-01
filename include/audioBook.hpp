#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "books.hpp"
#include "databaseConfig.hpp"
#include "dataBase.hpp"
#include <string>

class AudioBook : public Books
{
private:
 int hasAudioBook; 
 DataBaseConfig dataBaseName;
 Database *dataBase = new Database(dataBaseName.getDataBaseFileName());

public:
    AudioBook();
    void addAudioBook_();
    void getAudioBook_();
    void getAudioBookByName_();
    void getAudioBookByAuthor_();

    ~AudioBook();
};

#endif // AUDIOBOOK_H
