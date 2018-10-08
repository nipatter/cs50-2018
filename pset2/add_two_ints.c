/* How to define functions in c */

#include <stdio.h>
#include <cs50.h>

int add_two_ints(int a, int b);     // function prototype

int main(void)
{
    printf("First integer: ");
    int x = get_int();
    printf("Second integer: ");
    int y = get_int();

    int sum = add_two_floats(x, y);
    printf("%d\n", sum);
    return 0
}

int add_two_floats(int a, int b)    // function declaration
{
    return a + b;
}