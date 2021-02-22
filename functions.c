#include "perlin.h"

// Filters an input value (0 to 1.0) to a specified ASCII character.
char ascii_filter(double value) {
    if (value > 0.5) {
        if (value > 0.7) {
            return '@';
        }
        return '#';
    }
    return '~'; // water
}

// Expected vertical_size <= VERTICAL_SIZE, horizontal_size <= HORIZONTAL_SIZE
void generate_perlin_noise_map(double map[VERTICAL_SIZE][HORIZONTAL_SIZE], int vertical_size, int horizontal_size) {
    for (int i = 0; i < VERTICAL_SIZE; i++) {
        for (int j = 0; j < HORIZONTAL_SIZE; j++) {
            map[i][j] = perlin(i, j, 0.1, 4);
        }
    }
}

void print_map_raw(double map[VERTICAL_SIZE][HORIZONTAL_SIZE]) { 
    for (int i = 0; i < VERTICAL_SIZE; i++) {
        for (int j = 0; j < HORIZONTAL_SIZE; j++) {
            printf(" %lf ", map[i][j]);
        }
        printf("\n");
    }
}

void print_map(double map[VERTICAL_SIZE][HORIZONTAL_SIZE]) {
    for (int i = 0; i < VERTICAL_SIZE; i++) {
        for (int j = 0; j < HORIZONTAL_SIZE; j++) {
            printf(" %c ", ascii_filter(map[i][j]));
        }
        printf("\n");
    }
}