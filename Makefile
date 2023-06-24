SRC=src/main.c

CC=zcc

CFLAGS=+agon

all: a.bin

a.bin: $(SRC)
	$(CC) $(CFLAGS) src/main.c -o badapple.bin

clean:
	rm badapple.bin
