CC := g++

SRC_DIR := src
INC_DIR := inc
OBJ_DIR := obj
BIN_DIR := bin

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))
EXE := $(BIN_DIR)/executable

CFLAGS := -c -std=c++17 -I$(INC_DIR)
LFLAGS := -lsfml-system -lsfml-window -lsfml-graphics -lGL -lGLEW -lBox2D

all: $(OBJ)
	$(CC) $^ -o $(EXE) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $< -o $@ $(CFLAGS)

run: 
	@$(EXE)

clean:
	@rm $(OBJ_DIR)/*.o
