CC=gcc

CFLAGS=-g

SLL=./singlely-linked-list
DLL=./doublely-linked-list
QUE=./queue

SLL.o: singlely-linked-list/list.h
	$(CC) $(CFLAGS) -c $(SLL)/list.c
	mv list.o SLL.o

DLL.o: $(DLL)/list.h
	$(CC) $(CFLAGS) -c $(DLL)/list.c
	mv list.o DLL.o

queue.o: $(QUE)/queue.h
	$(CC) $(CFLAGS) -c $(QUE)/queue.c

main: SLL.o DLL.o queue.o
	$(CC) $(CFLAGS) main.c -o main SLL.o DLL.o queue.o

all: main

clean:
	rm *.o
