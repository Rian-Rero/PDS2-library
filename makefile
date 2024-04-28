CXX = g++
CXXFLAGS = -std=c++11 -Wall
BUILD_DIR = build
INCLUDE_DIR = include
SRC_DIR = src
DATABASE_DIR = database
LIBRARY_FILENAME = LibrarySoftware
DATABASE_FILENAME = LibraryDatabase

TARGET = $(BUILD_DIR)/$(LIBRARY_FILENAME)
DATABASE_TARGET = $(BUILD_DIR)/$(DATABASE_FILENAME)
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
INCLUDES := $(wildcard $(INCLUDE_DIR)/*.hpp)
LIBS = -lsqlite3

$(TARGET): $(OBJS) main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $@ main.cpp $(OBJS) $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean