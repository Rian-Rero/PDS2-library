#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include "books.hpp"
#include "dataBase.hpp"
#include "databaseConfig.hpp"

class Multimedia : public Books
{
private:
    int hasAudioBook;
    DataBaseConfig dataBaseName;
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());

public:
    Multimedia();
    void addMultimedia_();
    void getMultimedia_();
    void getMultimediaByName_();
    ~Multimedia();
};

#endif // MULTIMEDIA_H