/* A program that encrypts messages using a more advanced
 * version of Caesar's cypher called Vigenere's cypher.
 * Here the key is a word that translates the plaintext by the
 * corresponding letter of the keytext.
 */

// TODO: this doesnt catch whitespace in command line argument

#include <stdio.h>
#include <cs50.h>       // easy user input
#include <ctype.h>      // checking character types
#include <stdlib.h>     // atoi() and exit() functions
#include <string.h>     // strlen() function


int main(int argc, char *argv[])
{
    // checking that argv[1] is only text
    int argv_len = strlen(argv[1]);
    for (int c = 0; c < argv_len; c++)
    {
        if (isalpha(argv[1][c]) == 0)
        {
            printf("USAGE: ./vigenere ABC (where k is any length alphabet string)\n");
            exit(0);
        }
    }

    // turning argv[1] into a numeric key
    int keys[argv_len];
    for (int c = 0; c < argv_len; c++)
    {
        keys[c] = toupper(argv[1][c]) - 65;
    }

    // get the plain text to encrypt
    string plain_text = get_string("plaintext: ");
    int text_len = strlen(plain_text);

    // Vigenere encryption
    int j = 0;
    for (int i = 0; i < text_len; i++)
    {
        if (isalpha(plain_text[i]) && isupper(plain_text[i]))
        {
            printf("%c\n", ((plain_text[i] + keys[j] - 65) % 26) + 65);
            j = (j + 1) % argv_len;
        }
        else if (isalpha(plain_text[i]) && islower(plain_text[i]))
        {
            printf("%c\n", ((plain_text[i] + keys[j] - 97) % 26) + 97);
            j = (j + 1) % argv_len;
        }
        else
        {
            printf("%c\n", plain_text[i]);
        }
    }

    // print the cypher text
    printf("\n");
    return 0;
}