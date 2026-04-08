CC = gcc
CFLAGS = -Wall -Wextra -Iheader

SRCDIR = src
OBJDIR = build
HEADERDIR = header

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))
TARGET = compiler

.PHONY: all clean run dirs

all: dirs $(TARGET)

dirs:
	@mkdir -p $(OBJDIR)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET)

run: $(TARGET)
	./$(TARGET) "3 + 4 * 2"

test: $(TARGET)
	@echo "Testing expressions:"
	./$(TARGET) "10 + 5"
	./$(TARGET) "10 - 5"
	./$(TARGET) "10 * 5"
	./$(TARGET) "10 / 5"
	./$(TARGET) "(10 + 5) * 2"
	./$(TARGET) "10 + 5 * 2"
