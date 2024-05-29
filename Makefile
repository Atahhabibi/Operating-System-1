# Team Members
# Member 1: [Atah-Habibi], [ID:130699943]
# Member 2: [Matthew-Press], [ID:129894281]


CC = gcc
CFLAGS = -Wall -pthread
TARGET = bots

all: $(TARGET)

$(TARGET): main.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o

main.o: main.c threads.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(TARGET) *.o QUOTE.txt

