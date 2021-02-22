#ifndef PERLIN_H
#define PERLIN_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define vector2 struct (tuple/coordinate)
typedef struct {
    float x, y;
} vector2;

// Random seed
extern int seed;

// Map
#define HORIZONTAL_SIZE 50
#define VERTICAL_SIZE 50

// Colors
#define ANSI_RED "\x1b[31m"

// Function prototypes, perlin.c
int noise(int x, int y);
double linear_interpolation(double a, double b, double weight);
double cubic_interpolation(double a, double b, double weight);
vector2 random_gradient(int input_x, int input_y);
double dot_grid_gradient(int input_x, int input_y, double x, double y);
double perlin_noise(double x, double y);
double perlin(double x, double y, double frequency, int depth);

// Function prototypes, functions.c
char ascii_filter(double value);

#endif