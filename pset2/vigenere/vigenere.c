/* A program that encrypts messages using a more advanced
 * version of Caesar's cypher called Vigenere's cypher.
 * Here the key is a word that translates the plaintext by the
 * corresponding letter of the keytext.
 */

#include <stdio.h>
#include <cs50.h>       // easy user input
#include <ctype.h>      // checking character types
#include <stdlib.h>     // atoi() function
#include <string.h>     // strlen() function


int main(int argc, char *argv[])
{
    // checking that argv[1] is only text
    int c;
    int argv_len = strlen(argv[1]);
    for (c = 0; c < argv_len; c++)
    {
        if (isalpha(argv[1][c]) == 0)
            printf("not ok\n");
    }

    // turning argv[1] into a numeric key
    int keys[argv_len];
    for (c = 0; c < argv_len; c++)
    {
        keys[c] = toupper(argv[1][c]) - 65;
    }

    // get the plain text to encrypt
    string plain_text = get_string("plaintext: ");
    int text_len = strlen(plain_text);

    // Vigenere encryption
    int i, j = 0;
    char cipher_text[text_len];
    for (i = 0; i < text_len; i++)
    {
        if (isalpha(plain_text[i]) && isupper(plain_text[i]))
        {
            cipher_text[i] = ((plain_text[i] + keys[j] - 65) % 26) + 65;
            j = (j + 1) % argv_len;
        }
        else if (isalpha(plain_text[i]) && islower(plain_text[i]))
        {
            cipher_text[i] = ((plain_text[i] + keys[j] - 97) % 26) + 97;
            j = (j + 1) % argv_len;
        }
        else
        {
            cipher_text[i] = plain_text[i];
        }
    }

    // print the cipher text
    printf("%s\n", cipher_text);
    return 0;
}