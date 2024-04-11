CXX = g++
CXXFLAGS = -std=c++11 -Wall
BUILD_DIR = build

TARGET = $(BUILD_DIR)/LibrarySoftware
SRCS = main.cpp
OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: clean
