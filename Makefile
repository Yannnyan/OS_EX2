
CC = gcc
CFLAGS = -Wall -g
OBJ = main.o


%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) 

prog: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)





