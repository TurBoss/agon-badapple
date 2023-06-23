#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>

#include <graphics.h>

#define EQUALS(x, y) (strcmp(x, y) == 0)

int main(int argc, char const *argv[])
{
    char line[46];
    char c = "";

    int x = 0;
    int y = 0;

	char *file_path = "badapple.txt";

	FILE *fp= fopen(file_path, "r");

	if ( fp == NULL ) {
        printf("Can't open output text format file %s\n",file_path);
        return 1;
    }

    while(fgets(line, sizeof(line), fp) != NULL) { /* read a line from a file */

    	if (EQUALS(line, "*\n")) {
        	// clg();
    		// msleep();
    		y = 0;
    	}
    	else {
			for (x = 0; x < 45; x++) {
				c = line[x];
				// printf("char = %s\n ", c+64);

				if ((c == '1')) {
					unplot((x * 6) + 25, (y * 6) + 25);
				}
				else if ((c == '0')) {
					plot((x * 6) + 25, (y * 6) + 25);
				}
			}
			y++;
    	}
    }

	fclose(fp);

	return 0;
}
