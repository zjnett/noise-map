#include "perlin.h"

// Perlin noise-specific code largely adapted from https://en.wikipedia.org/wiki/Perlin_noise

// Original permutation array used by Ken Perlin. 256 integers with even distribution with values 0-255.
int permutation[] = { 151, 160, 137, 91, 90, 15, 131, 13, 201, 95, 96, 53, 194, 233, 7, 225, 140, 36, 
                      103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23, 190, 6, 148, 247, 120, 234, 75, 0, 
                      26, 197, 62, 94, 252, 219, 203, 117, 35, 11, 32, 57, 177, 33, 88, 237, 149, 56, 
                      87, 174, 20, 125, 136, 171, 168, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166, 
                      77, 146, 158, 231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55, 
                      46, 245, 40, 244, 102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 
                      187, 208, 89, 18, 169, 200, 196, 135, 130, 116, 188, 159, 86, 164, 100, 109, 
                      198, 173, 186, 3, 64, 52, 217, 226, 250, 124, 123, 5, 202, 38, 147, 118, 126, 
                      255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28, 42, 223, 183, 
                      170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221, 153, 101, 155, 167, 43, 
                      172, 9, 129, 22, 39, 253, 19, 98, 108, 110, 79, 113, 224, 232, 178, 185, 112, 
                      104, 218, 246, 97, 228, 251, 34, 242, 193, 238, 210, 144, 12, 191, 179, 162, 
                      241, 81, 51, 145, 235, 249, 14, 239, 107, 49, 192, 214, 31, 181, 199, 106, 
                      157, 184, 84, 204, 176, 115, 121, 50, 45, 127, 4, 150, 254, 138, 236, 205, 
                      93, 222, 114, 67, 29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156, 180 };

// Linear interpolation function. Interpolate between values a and b, provided weight is 0.0-1.0.
double linear_interpolation(double a, double b, double weight) {
    return (b - a) * weight + a;
}

// Cubic interpolation function
double cubic_interpolation(double a, double b, double weight) {
    return (b - a) * (3.0 - weight * 2.0) * weight * weight + a;
}

// Random Gradient. Generates a random direction vector.
vector2 random_gradient(int input_x, int input_y) {
    double random = 2920.f * sin(input_x * 21942.f + input_y * 171324.f + 8912.f) * cos(input_x * 23157.f * input_y * 217832.f + 9758.f);
    return (vector2) { .x = cos(random), .y = sin(random) };
}

// Calculate the dot product between direction and gradient.
double dot_grid_gradient(int input_x, int input_y, double x, double y) {
    // Get gradient from integer coordinates
    vector2 gradient = random_gradient(input_x, input_y);

    // Compute the distance vector
    double dx = x - (double) input_x;
    double dy = y - (double) input_y;

    // Compute the dot-product
    return (dx*gradient.x + dy*gradient.y);
}

// Perlin noise generation function for coordinates x and y
double perlin_noise(double x, double y) {
    // Determine grid cell coordinates
    int x0 = (int) x;
    int x1 = x0 + 1;
    int y0 = (int) y;
    int y1 = y0 + 1;

    // Determine interpolation weights
    double sx = x - (double) x0;
    double sy = y - (double) y0;

    // Interpolate between grid point gradients
    double n0, n1, ix0, ix1, value;

    n0 = dot_grid_gradient(x0, y0, x, y);
    n1 = dot_grid_gradient(x1, y0, x, y);
    ix0 = linear_interpolation(n0, n1, sx);

    n0 = dot_grid_gradient(x0, y1, x, y);
    n1 = dot_grid_gradient(x1, y1, x, y);
    ix1 = linear_interpolation(n0, n1, sx);

    value = linear_interpolation(ix0, ix1, sy);
    return value;
}

// Perlin wrapper function
// Adapted from https://gist.github.com/nowl/828013
double perlin(double x, double y, double frequency, int depth) {
    double xa = x * frequency;
    double ya = y * frequency;
    double amplitude = 1.0;
    double final = 0;
    double divisor = 0.0;

    for(int i = 0; i < depth; i++) {
        divisor += 256 * amplitude;
        final += perlin_noise(xa, ya) * amplitude;
        amplitude /= 2;
        xa *= 2;
        ya *= 2;
    }

    return final / divisor;
}