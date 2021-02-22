#include "perlin.h"

extern int seed;

int main(int argc, char *argv[]) {
    
    srand(time(NULL));

    double map[VERTICAL_SIZE][HORIZONTAL_SIZE] = { { 0 } };

    // Generate random seed
    seed = rand() % 256;

    // Generate perlin noise for map
    for (int i = 0; i < VERTICAL_SIZE; i++) {
        for (int j = 0; j < HORIZONTAL_SIZE; j++) {
            map[i][j] = perlin(i, j, 0.1, 4);
        }
    }

    // Print out raw numbers
    for (int i = 0; i < VERTICAL_SIZE; i++) {
        for (int j = 0; j < HORIZONTAL_SIZE; j++) {
            printf(" %lf ", map[i][j]);
        }
        printf("\n");
    }

    // Print out ASCII-filtered map
    for (int i = 0; i < VERTICAL_SIZE; i++) {
        for (int j = 0; j < HORIZONTAL_SIZE; j++) {
            printf(" %c ", ascii_filter(map[i][j]));
        }
        printf("\n");
    }

    return 0;
}