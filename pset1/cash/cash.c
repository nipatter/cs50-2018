/* A program that calculates the minimum amount of coins
 * to give back to the customer as their change.
 * Implementation of a greedy algorithm
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float change;
    int total_coins = 0;

    // get the amount of change owed to the customer
    do
    {
        change = get_float("change owed: ");
    }
    while (change < 0);

    while (change >= 0.25)
    {
        total_coins++;
        change -= 0.25;
        // printf("change remaining: %f\n", change);
    }

    while (change >= 0.1)
    {
        total_coins++;
        change -= 0.1;
        // printf("change remaining: %f\n", change);
    }

    while (change >= 0.05)
    {
        total_coins++;
        change -= 0.05;
        // printf("change remaining: %f\n", change);
    }

    while (change > 0.00)
    {
        total_coins++;
        change -= 0.01;
        // printf("change remaining: %f\n", change);
    }
    printf("%d\n", total_coins);
    return 0;
}
