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