#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include <graphics.h>

#define PIXEL_SIZE 12

#define LINE_CHARS 46
#define LINES_FRAME 30

#define OFFSET_X 30
#define OFFSET_Y 10


int displayBuffer[LINE_CHARS][LINES_FRAME] = { };
int prevDisplayBuffer[LINE_CHARS][LINES_FRAME] = { };

int main(void)
{
	// gfx_set_fatpix(true);

	int screen_w = getmaxx();
	int screen_h = getmaxy();

	int pixel_w = screen_w / LINE_CHARS ;
	int pixel_h = screen_h / LINES_FRAME;

//	printf("%d %d", screen_w, screen_h);

    int x = 0;
    int y = 0;

    int a = 0;
    int b = 0;

    int pixel_pos_x = 0;
    int pixel_pos_y = 0;

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
    		for (a = 0; a < LINE_CHARS; a++) {
    			for (b = 0; b < LINES_FRAME; b++) {
    				if (displayBuffer[a][b] != prevDisplayBuffer[a][b]) {

    					if (displayBuffer[a][b] == true) {
    						plot(a * pixel_w, b * pixel_h);
    					}
    					else {
    						unplot(a * pixel_w, b * pixel_h);
    					}

        				prevDisplayBuffer[a][b] = displayBuffer[a][b];
    				}
    			}
    		}

    		y = 0;
    	}
    	else {
    		for(x = 0; x < LINE_CHARS; x++) {
    			c = line[x];

    			pixel_pos_x = (x * pixel_w) + OFFSET_X;
				pixel_pos_y = (y * pixel_h) + OFFSET_Y;

				if (c == '1') {
					displayBuffer[x][y] = true;
				}
				else if (c == '0') {
					displayBuffer[x][y] = false;
				}
    		}
			y++;
    	}
    }



	fclose(fp);

	return 0;
}
