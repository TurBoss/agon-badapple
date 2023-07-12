SRC=src/main.c

CC=zcc

CFLAGS=+agon -pragma-define:CRT_ENABLE_COMMANDLINE=0 -pragma-define:CLIB_DEFAULT_SCREEN_MODE=2


all: a.bin

a.bin: $(SRC)
	$(CC) $(CFLAGS) src/main.c -o badapple.bin

clean:
	rm badapple.bin
