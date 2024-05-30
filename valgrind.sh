#!/bin/bash

# Compilar o programa
make

# Verificar se a compilação foi bem-sucedida
if [ $? -eq 0 ]; then
    # Executar o programa
    valgrind --leak-check=full ./bin/LibrarySoftware
else
    echo "Erro na compilação. Por favor, corrija os erros e tente novamente."
fi