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
    char line[152];
    char c;

    int x = 0;
    int y = 0;

	char *file_path = "badapple.txt";

	FILE *fp= fopen(file_path, "r");

	if ( fp == NULL ) {
        printf("Can't open output text format file %s\n",file_path);
        return 1;
    }

    while(fgets(line, sizeof(line), fp) != NULL) { /* read a line from a file */

    	if (EQUALS(line, "nekomark\n")) {
        	clg();

    		//printf("NEKO");

    		y = 0;
    	}
		for (x = 0; x < 151; x++) {
			c = line[x];

			if (EQUALS(c, '.')) {
//				circle(x*3,  y*4, 2, true);
				//circle(x,  y, 1, true);
//				point(x, y);
				//circle(x*3, y*3, 3, true);
			}
			else if (EQUALS(c, '@')) {
				// point(x, y);
				circle(x*3,  y*4, 2, false);
//				drawr(x, y);
//				circle(x, y, 1, false);
			}
		}
    	y++;
    }

	fclose(fp);

	return 0;
}
