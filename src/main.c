#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <graphics.h>



#define OFFSET_X 25
#define OFFSET_Y 25

#define SPACE_X 8
#define SPACE_Y 8


#define EQUALS(x, y) (strcmp(x, y) == 0)


int main(int argc, char const *argv[])
{

//	int screen_w = getmaxx();
//	int screen_h = getmaxy();
//
//	printf("%d %d", screen_w, screen_h);

    int x = 0;
    int y = 0;

	char *file_path = "badapple.txt";
	char line[46];
    char c = "";

	FILE *fp= fopen(file_path, "r");

	if ( fp == NULL ) {
        printf("Can't open file %s\n",file_path);
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

				if ((c == '1')) {
					unplot((x * SPACE_X) + OFFSET_X, (y * SPACE_Y) + OFFSET_Y);
				}
				else if ((c == '0')) {
					plot((x * SPACE_X) + OFFSET_X, (y * SPACE_Y) + OFFSET_Y);
				}
			}
			y++;
    	}
    }

	fclose(fp);

	return 0;
}
