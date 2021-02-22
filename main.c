#include "perlin.h"

extern int seed;

int main(int argc, char *argv[]) {
    
    srand(time(NULL));

    double map[10][10] = { { 0 } };

    // Generate random seed
    seed = rand() % 256;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = perlin(i, j, 0.1, 4);
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf(" %lf ", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}