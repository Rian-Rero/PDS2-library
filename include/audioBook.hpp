#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "books.hpp"
#include "databaseConfig.hpp"
#include "dataBase.hpp"
#include <string>

/**
 * @brief Classe que representa um AudioBook derivado de Books
 */
class AudioBook : public Books
{
private:
    int hasAudioBook;                                                      ///< Indica se há um audiobook disponível
    DataBaseConfig dataBaseName;                                           ///< Configuração do banco de dados
    Database *dataBase = new Database(dataBaseName.getDataBaseFileName()); ///< Ponteiro para o banco de dados

public:
    /**
     * @brief Construtor padrão da classe AudioBook
     */
    AudioBook();

    /**
     * @brief Adiciona um audiobook
     */
    void addAudioBook_();

    /**
     * @brief Obtém todos os audiobooks
     */
    void getAudioBook_();

    /**
     * @brief Obtém um audiobook pelo nome do livro
     */
    void getAudioBookByName_();

    /**
     * @brief Obtém um audiobook pelo nome do autor
     */
    void getAudioBookByAuthor_();

    /**
     * @brief Destrutor da classe AudioBook
     */
    ~AudioBook();
};

#endif // AUDIOBOOK_H
