// check if a triangle like this can exist

#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

bool valid_triangle(float a, float b, float c);
float x, y, z;

int main(void) {
    do {
        x = get_float("First side length: ");
    } while (x =< 0);

    do {
        y = get_float("Second side length: ");
    } while (y =< 0);

    do {
        z = get_float("Third side length: ");
    } while (z =< 0);


    if (valid_triangle(x, y, z) == true) {
        printf("Valid triangle\n");
    }
    else {
        printf("Invalid triangle\n");
    }
}


bool valid_triangle(float a, float b, float c) {
    if (a + b >= c) {
        return true;
    }
    else if (a + c >= b) {
        return true;
    }
    else if (b + c >= a) {
        return true;
    }
    else {
        return false;
    }
}
