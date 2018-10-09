/* A program that encrypts messages using Caesar's cypher.
 * Caesar's cypher is a simple letter shifting scramble.
 */

#include <stdio.h>
#include <cs50.h>       // easy user input
#include <ctype.h>      // checking character types
#include <stdlib.h>     // atoi() and exit() function
#include <string.h>     // strlen() function

int main(int argc, char *argv[])
{
    int key = atoi(argv[1]);
    if (isdigit(key) == 0)
    {
        printf("USAGE: ./caesar k (where k is an integer)\n");
        exit(0);
    }

    string plain_text = get_string("plaintext: ");

    int i;
    int text_len = strlen(plain_text);
    for (i = 0; i < text_len; i++)
    {
        if (isalpha(plain_text[i]) && isupper(plain_text[i]))
            printf("%c", ((plain_text[i] + key - 65) % 26) + 65);
        else if (isalpha(plain_text[i]) && islower(plain_text[i]))
            printf("%c", ((plain_text[i] + key - 97) % 26) + 97);
        else
            printf("%c", plain_text[i]);
    }
    printf("\n");
    return 0;
}