CC = gcc
CFLAGS = -Wall
LDFLAGS =
OBJFILES = stack.o stack_test.o
TARGET = stack_test

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~
