CC := g++
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

EXE := $(BIN_DIR)/Homework
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

.PHONY: all clean

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) -c src/main.cpp -o obj/main.o
	$(CC) -c src/structures.cpp -o obj/structures.o
	$(CC) -c src/functions.cpp -o obj/functions.o

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(OBJ) -o $(EXE)

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)