/* A program that draws pyramids of specified height by the user.
 * In the more version a full pyramid is drawn
 * with two spaces separating the two halves.
 */

#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

int main(void) {
    int h, i, j;

    // get an integer from the user for the height of the pyramid
    do {
        h = get_int("height: ");
    } while (h < 0 || h > 23);

    // loop to build the pyramid
    for (i = 0; i < h; i++)
        {
        for (j = 0; j <= h - i; j++)
        {
            printf(" ");
        }
        for (j = 0; j < 2 + i; j++)
        {
            printf("#");
        }
        printf("  ");   //the space between the two halves
        for (j = 0; j < 2 + i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}