/* A program that encrypts messages using Caesar's cypher.
 * Caesar's cypher is a simple letter shifting scramble.
 */

#include <stdio.h>
#include <cs50.h>       // easy user input
#include <ctype.h>      // checking character types
#include <stdlib.h>     // atoi() function
#include <string.h>     // strlen() function


int main(int argc, char *argv[])
{
    int key = atoi(argv[1]);

    string plain_text = get_string("plaintext: ");

    int i;
    int text_len = strlen(plain_text);
    char cipher_text[text_len];
    for (i = 0; i < text_len; i++)
    {
        if (isalpha(plain_text[i]) && isupper(plain_text[i]))
            cipher_text[i] = ((plain_text[i] + key - 65) % 26) + 65;
        else if (isalpha(plain_text[i]) && islower(plain_text[i]))
            cipher_text[i] = ((plain_text[i] + key - 97) % 26) + 97;
        else
            cipher_text[i] = plain_text[i];
    }
    printf("%s\n", cipher_text);
    return 0;
}