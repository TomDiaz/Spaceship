CC = g++
CFLAGS = -Iinclude -Wall -g
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SRC = src/main.cpp src/utils.cpp
OBJ_DIR = build
OBJ = $(SRC:src/%.cpp=$(OBJ_DIR)/%.o)
TARGET = app

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: src/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ) $(TARGET)
	rm -rf $(OBJ_DIR)