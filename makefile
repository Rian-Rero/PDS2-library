CXX := g++
CXXFLAGS := -Wall -Wextra -Werror -std=c++11
SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build
BIN_DIR := bin
DATABASE_DIR := database
LIBS := -lsqlite3 -lcryptopp
LIBRARY_FILENAME := LibrarySoftware
DATABASE_FILENAME := LibraryDatabase

# Obtém todos os arquivos .cpp em SRC_DIR
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Obtém todos os arquivos .hpp em INCLUDE_DIR
HEADERS := $(wildcard $(INCLUDE_DIR)/*.hpp)

# Gera o nome dos arquivos de objeto para cada arquivo .cpp
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Nome do executável
EXEC := $(BIN_DIR)/$(LIBRARY_FILENAME)
DATABASE_EXEC := $(BIN_DIR)/$(DATABASE_FILENAME)

# Define a regra 'all' como padrão
all: $(EXEC) $(DATABASE_EXEC)

# Regra para compilar cada arquivo de objeto
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Regra de compilação final para o primeiro executável
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LIBS)
	@echo "Executável gerado em $(EXEC)"

# Regra de compilação final para o segundo executável
$(DATABASE_EXEC): $(BUILD_DIR) $(DATABASE_DIR)/readDatabase.cpp
	$(CXX) $(CXXFLAGS) -o $@ $(DATABASE_DIR)/readDatabase.cpp $(LIBS)
	@echo "Executável gerado em $(DATABASE_EXEC)"

# Regra para limpar arquivos compilados
clean:
	@rm -rf $(BUILD_DIR)/*.o $(BIN_DIR)/$(LIBRARY_FILENAME) $(BIN_DIR)/$(DATABASE_FILENAME)
	@echo "Arquivos de objeto e executáveis limpos"

# Cria os diretórios de build e bin caso não existam
$(shell mkdir -p $(BUILD_DIR))
$(shell mkdir -p $(BIN_DIR))



# Define a regra 'clean' para limpar arquivos compilados
.PHONY: all clean