CC= gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET= A6
all: $(TARGET)
$(TARGET):A6.o
	$(CC) $(CFLAGS) -o $(TARGET) A6.o

clean:
	rm $(TARGET)
