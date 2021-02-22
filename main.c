#include "perlin.h"

extern int seed;

int main(int argc, char *argv[]) {
    // Expected argc = 3
    // Expected argv = { "perlin", "vertical_size", "horizontal_size" }

    int vertical = 0, horizontal = 0;

    if (argc == 3) {
        vertical = atoi(argv[1]);
        horizontal = atoi(argv[2]);
        if (vertical > VERTICAL_SIZE) {
            vertical = VERTICAL_SIZE;
        }
        if (horizontal > HORIZONTAL_SIZE) {
            horizontal = HORIZONTAL_SIZE;
        }
    } else {
        vertical = 20;
        horizontal = 20;
    }

    srand(time(NULL));

    double map[VERTICAL_SIZE][HORIZONTAL_SIZE] = { { 0 } };

    // Generate random seed
    seed = rand() % 256;

    // Generate perlin noise for map
    generate_perlin_noise_map(map, vertical, horizontal);

    // Print out raw numbers
    print_map_raw(map, vertical, horizontal);

    // Print out ASCII-filtered map
    print_map(map, vertical, horizontal);

    return 0;
}