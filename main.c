#include "perlin.h"

extern int seed;

int main(int argc, char *argv[]) {
    
    srand(time(NULL));

    double map[VERTICAL_SIZE][HORIZONTAL_SIZE] = { { 0 } };

    // Generate random seed
    seed = rand() % 256;

    // Generate perlin noise for map
    generate_perlin_noise_map(map, VERTICAL_SIZE, HORIZONTAL_SIZE);

    // Print out raw numbers
    print_map_raw(map, 10, 10);

    // Print out ASCII-filtered map
    print_map(map, 10, 10);

    return 0;
}