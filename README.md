O projeto necessita de duas bibliotecas grandes que não costumam vir instaladas nas distribuições padrões de Sistemas Operacionais, por isso é necessário seguir os seguintes passos:

Bibliteocas:
-> SQLite3
-> Crypto

Comandos para instalação:

sudo apt-get install libsqlite3-dev
sudo apt-get install libcrypto++-dev

---

Passo a Passo para utilização do Software:

O aplicativo existem 3 scripts responsáveis por manipula-lo, sendo eles:

-> run.sh : ==> É o padrão que deve ser utilizado, ele compila todos arquivos e já executa o aplicativo.

-> valgrind.sh : ==> É o responsável por monitorar alocação de memória, ele primeiramente compila todos os arquivos e executa o aplicativo usando os comandos do Valgrind para a lógica de monitoramento de memória.

-> getDataBase.sh : ==> É o responsável apenas para ler o banco de dados SQL, ele compila todos os arquivos e executa o arqivo readDatabase.cpp após a compilação com êxito.

============================================================================================================================

Olá, este é o repositório criado para o trabalho prático de PDS II, ministrado pelo professor Pedro Saint Clair.
Integrantes do grupo:
-Rian Rero
-Victor Rezende
-Matheus Madeira
-Gabriel Hermont

Nosso trabalho basicamente se resume na criação de uma biblioteca. Essa biblioteca terá a necessidade de suprir as seguintes funções:
1- Criação de usuários: O nosso sistema bibliotecário terá como objetivo a criação de um para facilitação de controle de possíveis clientes da biblioteca
2- Cadastro de livros: Nosso sistema também irá possibilitar a criação de um inventário de livros que possibilita o controle do estoque e também da coleção de livros da biblioteca.
3- Pesquisa de livros: Nosso sistema também terá como função a pesquisa de livros que se encontrarão em nossa coleção, permitindo assim que a busca fique mais fácil e agilize todo o processo.
4- Reserva de Livro: Outra funcionalidade do nosso sistema será a possibilidade de usuários cadastros poderem reservar livros, garantindo que o controle seja garantido de maneira controlada e segura.
5- Renovação da reserva: Por fim, nosso sistema possibilitará que um usuário que se encontra com uma reserva ativa, possa renová-la a fim de permanecer com o livro por um maior tempo
