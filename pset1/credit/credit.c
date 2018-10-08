/* A program that validates a credit card number by checksum and
 * if it is, returns the issuing credit card company.
 * Implementation of Luhn's algorithm for the checksum
 */

#include <stdio.h>
#include <cs50.h>   // for getting user input easily
#include <math.h>   // for pows and fmods

int card_length(long long Num);
int checksum(long long Num);
void categorise(long long Num, int digit_total);

int main(void)
{
    /* long long ccNum = 378282246310005; this is a test number */
    // eprintf("%lld\n", ccNum);

    /* get the credit card number */
    long long ccNum;
    do
    {
        ccNum = get_long_long("credit card number: ");
    }
    while (ccNum <= 0);

    /* Find length of card number */
    int l = card_length(ccNum);

    /* Card validation and identification */
    if (13 <= l && l <= 16)
    {
        if (checksum(ccNum) == 1)
        {
            categorise(ccNum, l);
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

int card_length(long long Num)
{
    /* Get the number of digits in the card number */
    int digits = 0;
    while(Num > 0)
    {
        Num /= 10;
        digits++;
    }
    return digits;
}

int checksum(long long Num)
{
    /* Checksum using Luhn's algorithm */

    /*Multiply every other digit by 2, starting with the number’s second-to-last digit */
    int i;
    int e = 1;
    int even_nums[8];
    for (i = 0; i < 8; i++, e += 2)
    {
        even_nums[i] = fmod(Num / pow(10, e), 10);
        even_nums[i] *= 2;
    }    // Use the debugger to figure out why you cant * 2 in the same line

    /* Add those products' digits together. */
    int j;
    int total = 0;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 2; j++)
        {
            total += fmod(even_nums[i] / pow(10, j), 10);
        }
    }

    /* Add the sum to the sum of the digits that weren’t multiplied by 2. */
    e = 0;
    for (i = 0; i < 8; i++, e += 2)
    {
        total += fmod(Num / pow(10, e), 10);
    }

    /* If the total’s last digit is 0 the number is valid! */
    if (total % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void categorise(long long Num, int digit_total)
{
    /* Return the name of the issuing card company */
    int first_two_nums[2], i;
    digit_total--;
    for (i = 0; i < 2; i++, digit_total--)
    {
        first_two_nums[i] = fmod(Num / pow(10, digit_total), 10);
    }

    /* Visa begins with 4 */
    if (first_two_nums[0] == 4)
    {
        printf("VISA\n");
    }
    /* AMEX begins with 34 or 37 */
    else if (first_two_nums[0] == 3)
    {
        if (first_two_nums[1] == 4 || first_two_nums[1] == 7)
            {
                printf("AMEX\n");
            }
    }
    /* Mastercard begins with 51, 52, 53, 54, or 55 */
    else if (first_two_nums[0] == 5)
    {
        printf("MASTERCARD\n");
    }
}