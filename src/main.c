#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include <graphics.h>

#define LINE_CHARS 46
#define LINES_FRAME 30

#define OFFSET_X 30
#define OFFSET_Y 10


int main(int argc, char const *argv[])
{

	int screen_w = getmaxx();
	int screen_h = getmaxy();

	int pixel_w = screen_w / LINE_CHARS ;
	int pixel_h = screen_h / LINES_FRAME;

//	printf("%d %d", screen_w, screen_h);

    int x = 0;
    int y = 0;

	char *file_path = "badapple.txt";

	char line[LINE_CHARS];
    char c = "";

	FILE *fp= fopen(file_path, "r");

	if ( fp == NULL ) {
        printf("Can't open file %s\n", file_path);
        return 1;
    }

    while(fgets(line, sizeof(line), fp) != NULL) {

    	if (line[0] == '*') {
    		//msleep(10000);
    		//clg();
    		y = 0;
    	}
    	else {
    		for(x = 0; x < LINE_CHARS; x++) {
    			c = line[x];

				if (c == '1') {
					unplot((x * pixel_w) + OFFSET_X, (y * pixel_h) +OFFSET_Y);
				}
				else if (c == '0') {
					plot((x * pixel_w) + OFFSET_X, (y * pixel_h) +OFFSET_Y);
				}
    		}
			y++;
    	}
    }

	fclose(fp);

	return 0;
}
