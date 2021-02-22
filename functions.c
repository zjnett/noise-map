#include "perlin.h"

// Filters an input value (0 to 1.0) to a specified ASCII character.
char ascii_filter(double value) {
    if (value > 0.5) {
        if (value > 0.58) {
            if (value > 0.65) {
                if (value > 0.8) {
                    return '?';
                }
                return '@';
            }
            return '"';
        }
        return '#';
    }
    return '~'; // water
}

char *color_filter(char value) {
    int random_var = 0;
    switch(value) {
        case '~':
            random_var = rand() % 2;
            return random_var ? ANSI_BLUE : ANSI_BRIGHT_BLUE;
        case '#':
            return ANSI_YELLOW;
        case '"':
            return ANSI_GREEN;
        case '@':
            return ANSI_GRAY;
        case '?':
            return ANSI_WHITE;
    }
    return NULL;
}

// Expected vertical_size <= VERTICAL_SIZE, horizontal_size <= HORIZONTAL_SIZE
void generate_perlin_noise_map(double map[VERTICAL_SIZE][HORIZONTAL_SIZE], int vertical_size, int horizontal_size) {
    for (int i = 0; i < vertical_size; i++) {
        for (int j = 0; j < horizontal_size; j++) {
            map[i][j] = perlin(i, j, 0.1, 4);
        }
    }
}

void print_map_raw(double map[VERTICAL_SIZE][HORIZONTAL_SIZE], int vertical_size, int horizontal_size) { 
    for (int i = 0; i < vertical_size; i++) {
        for (int j = 0; j < horizontal_size; j++) {
            printf(" %lf ", map[i][j]);
        }
        printf("\n");
    }
}

void print_map(double map[VERTICAL_SIZE][HORIZONTAL_SIZE], int vertical_size, int horizontal_size) {
    for (int i = 0; i < vertical_size; i++) {
        for (int j = 0; j < horizontal_size; j++) {
            char token = ascii_filter(map[i][j]);
            char *color = color_filter(token);
            printf("%s %c ", color, token);
        }
        printf("\n");
    }
    // reset color buffer
    printf(ANSI_RESET);
}