# 定义编译器和编译选项
CC = gcc
CFLAGS = -Wall

# 定义目标文件和依赖文件
TARGET = myprogram
OBJS = *.c

# 默认编译规则
all: $(TARGET)

# 生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 编译每个源文件
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# 清理中间文件和可执行文件
clean:
	rm -f $(TARGET) $(OBJS)