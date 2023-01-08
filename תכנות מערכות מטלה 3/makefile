CC = gcc
CFLAGS = -Wall -g
.PHONY: all clean
all: isort txtfind



txtfind: txtfind.o
	$(CC) $(CFLAGS) txtfind.o -o txtfind -lm 


isort: isort.o
	$(CC) $(CFLAGS) isort.o -o isort -lm


clean:
	rm -f  isort txtfind *.o
