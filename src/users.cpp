#include "users.hpp"
#include "dataBase.hpp"

using namespace std;

/**
 * @brief Construtor da classe Users.
 */
Users::Users()
{
    name = "";
    email = "";
    password = "";
};

/**
 * @brief Destrutor da classe Users.
 */
Users::~Users(){};

/**
 * @brief Função para criar um novo usuário.
 *
 * @details Solicita ao usuário que insira nome, email e senha,
 * em seguida, chama a função do banco de dados para criar o usuário.
 */
void Users::createUser_()
{

    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());
    cin.ignore();
    string name, email, password;
    cout << "Digite o nome do usuário: ";
    getline(cin, name);

    cout << "Digite o email do usuário: ";
    getline(cin, email);

    cout << "Digite a senha do usuário: ";
    getline(cin, password);

    try
    {
        dataBase->createUser(name, email, password);
    }
    catch (const exception &e)
    {
        cerr << "Erro ao criar o usuário: " << e.what() << endl;
    }

    delete dataBase;
}

/**
 * @brief Função para obter o email do usuário.
 *
 * @return Email do usuário.
 */
string Users::getEmail()
{
    return email;
}

/**
 * @brief Função para obter o nome do usuário.
 *
 * @return Nome do usuário.
 */
string Users::getName()
{
    return name;
}

/**
 * @brief Função para verificar se o usuário é administrador.
 *
 * @return 1 se for administrador, 0 caso contrário.
 */
int Users::isAdmin()
{
    return admin;
}

/**
 * @brief Função para definir o nome do usuário.
 *
 * @param name Nome do usuário.
 */
void Users::setName(string name)
{
    this->name = name;
}
/**
 * @brief Função para definir o email do usuário.
 *
 * @param email Email do usuário.
 */
void Users::setEmail(string email)
{
    this->email = email;
}

/**
 * @brief Função para definir se o usuário é administrador ou não.
 *
 * @param admin 1 para administrador, 0 caso contrário.
 */
void Users::setAdmin(int admin)
{
    this->admin = admin;
}

/**
 * @brief Função para realizar login.
 *
 * @details Solicita ao usuário que insira o email e a senha,
 * em seguida, chama a função do banco de dados para verificar as credenciais.
 *
 * @param users Ponteiro para objeto Users onde os detalhes do usuário serão armazenados.
 *
 * @return Verdadeiro se o login for bem-sucedido, falso caso contrário.
 */
bool Users::login_(Users *users)
{

    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());
    cin.ignore();
    string email, password;
    cout << "Digite o email do usuário: ";
    getline(cin, email);

    cout << "Digite a senha do usuário: ";
    getline(cin, password);

    bool loginSuccessful = false;
    try
    {
        if (dataBase->login(email, password, users))
            loginSuccessful = true;
        else
            loginSuccessful = false;
    }
    catch (const exception &e)
    {
        cerr << "Erro ao logar o usuário: " << e.what() << endl;
    }

    delete dataBase;

    return loginSuccessful;
}

/**
 * @brief Função para obter todos os usuários do banco de dados.
 */
void Users::getAllUsers_()
{

    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());
    try
    {
        dataBase->getUsers();
    }
    catch (const exception &e)
    {
        cerr << "Erro ao buscar os usuários: " << e.what() << endl;
    }

    delete dataBase;
}

/**
 * @brief Função para atualizar as informações de um usuário.
 *
 * @details Solicita ao usuário que insira o ID do usuário que será atualizado,
 * em seguida, chama a função do banco de dados para realizar a atualização.
 */
void Users::updateUser_()
{

    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());
    cin.ignore();
    int ID;
    cout << "Digite o ID do usuário que deseja tornar administrador: ";
    cin >> ID;
    try
    {
        dataBase->updateUser(ID);
    }
    catch (const exception &e)
    {
        cerr << "Erro ao tornar o usuário um administrador: " << e.what() << endl;
    }
    delete dataBase;
}

/**
 * @brief Função para obter o tipo de usuário (ex: admin, cliente) com base no email.
 *
 * @param email Email do usuário.
 *
 * @return Tipo de usuário.
 */
string Users::getUserType_(const string &email)
{

    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());
    string position = dataBase->getUserType(email);
    delete dataBase;
    return position;
}

/**
 * @brief Função para obter o ID do usuário com base no email.
 *
 * @param email Email do usuário.
 *
 * @return ID do usuário.
 */
int Users::getID_(string email)
{

    Database *dataBase = new Database(dataBaseName.getDataBaseFileName());
    int ID = dataBase->getID(email.c_str());
    delete dataBase;
    return ID;
}

void Users::displayInfo()
{
    cout << "Nome: " << getName() << endl;
    cout << "Email: " << getEmail() << endl;
}