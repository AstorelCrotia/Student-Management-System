CC = gcc
CFLAGS = -Wall
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
TARGET = $(BINDIR)/彩票管理系统.exe
all: $(TARGET)
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)
clean:
	rm -f $(OBJDIR)/*.o $(TARGET)