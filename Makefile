# 检测操作系统
ifeq ($(OS),Windows_NT)
    # Windows 配置
    CC = gcc
    CFLAGS = -Wall -Wextra -g -Iinclude
    LDFLAGS = -lpdcurses
    EXE_EXT = .exe
else
    # Linux/macOS 配置
    CC = gcc
    CFLAGS = -Wall -Wextra -g -Iinclude
    LDFLAGS = -lncurses
    EXE_EXT = 
endif

SRC_DIR = src
INC_DIR = include
BIN_DIR = bin
OBJ_DIR = obj

# 使用wildcard自动获取源文件
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
TARGET = $(BIN_DIR)/snake$(EXE_EXT)

# 测试相关设置
TEST_DIR = test
TEST_SRCS = $(TEST_DIR)/snake_test.c
TEST_OBJS = $(patsubst $(TEST_DIR)/%.c,$(OBJ_DIR)/%.o,$(TEST_SRCS))
TEST_TARGET = $(TEST_DIR)/snake_test$(EXE_EXT)

# 除了main.o之外的所有源文件用于测试
SNAKE_OBJS = $(filter-out $(OBJ_DIR)/main.o, $(OBJS))

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# 测试目标
.PHONY: test

# 编译测试文件
$(OBJ_DIR)/snake_test.o: $(TEST_DIR)/snake_test.c $(DEPS)
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 链接测试程序
test: $(SNAKE_OBJS) $(TEST_OBJS)
	$(CC) $(SNAKE_OBJS) $(TEST_OBJS) -o $(TEST_TARGET) $(LDFLAGS)
	./$(TEST_TARGET)

# 清理规则
clean:
ifeq ($(OS),Windows_NT)
	if exist $(OBJ_DIR) rmdir /s /q $(OBJ_DIR)
	if exist $(BIN_DIR) rmdir /s /q $(BIN_DIR)
	if exist $(TEST_TARGET) del $(TEST_TARGET)
else
	rm -f $(OBJS) $(TEST_OBJS)
	rm -f $(TARGET) $(TEST_TARGET)
	rm -rf $(BIN_DIR)
	rm -rf $(OBJ_DIR)
endif

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run