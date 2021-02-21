#include "perlin.h"

extern int permutation[];

int main(int argc, char *argv[]) {
    
    double map[10][10] = { { 0 } };

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