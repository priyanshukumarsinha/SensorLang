SRC_DIR = .
LEXER_DIR = lexer
BUILD_DIR = build

SRCS = $(SRC_DIR)/main.cpp \
	   $(LEXER_DIR)/lexer.cpp

OBJS = $(BUILD_DIR)/main.o \
	   $(BUILD_DIR)/lexer.o

# ifeq ($(OS),Windows_NT)
# 	TARGET = $(BUILD_DIR)/sensorlang.exe
# else
# 	TARGET = $(BUILD_DIR)/sensorlang
# endif
TARGET = $(BUILD_DIR)/sensorlang.exe


all: $(TARGET)

# Build Executable
$(TARGET):$(OBJS)
	@mkdir -p $(BUILD_DIR)
	g++ -o $(TARGET) $(OBJS)

# create main.o as in OBJS
$(BUILD_DIR)/main.o: main.cpp lexer/lexer.h lexer/token.h
	@mkdir -p $(BUILD_DIR)
	g++ -I. -c main.cpp -o $(BUILD_DIR)/main.o

# create lexer.o as in OBJS
$(BUILD_DIR)/lexer.o: lexer/lexer.cpp lexer/lexer.h lexer/token.h
	@mkdir -p $(BUILD_DIR)
	g++ -I. -c $(LEXER_DIR)/lexer.cpp -o $(BUILD_DIR)/lexer.o


clean:
	rm -rf $(BUILD_DIR)
