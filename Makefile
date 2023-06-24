SRC=src/main.c

CC=zcc

CFLAGS=+agon
LDFLAGS=-lm

all: a.bin

a.bin: $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) src/main.c -o badapple.bin

clean:
	rm badapple.bin
