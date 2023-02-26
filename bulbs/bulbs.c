#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

int powers_of_two(int n);
void print_bulb(int bit);

int main(void)
{
    // ask user for message
    string message = get_string("Message: ");

    // determine the length of the string
    int l = strlen(message);


    // convert the string into a series of decimal numbers
    int dec_message[l];      // array of decimal numbers (used for converting the message to a series of decimal numbers)
    for (int i = 0; i < l; i++)
    {
        dec_message[i] = message[i];
    }

    // convert the string into a series of 8-bit binary numbers
    for (int i = 0; i < l; i++)     // iterate through the array of decimal numbers
    {
        int dec = dec_message[i];

        for (int j = BITS_IN_BYTE - 1; j >= 0; j--)        // iterate through the 8 bits in order to convert the first number of the array to a binary number
        {
            int boolean = dec / powers_of_two(j);       // determine quotient
            if (boolean == 0)
            {
                print_bulb(boolean);        // print dark emoji
            }
            else if (boolean == 1)
            {
                print_bulb(boolean);        // print light emoji
                dec -= powers_of_two(j);        // calculate remainder
            }
        }
        printf("\n");       // print new line after 8 bits
    }
}


int powers_of_two(int e)        // calculates powers of two for a given exponent e
{
    int result = 1;
    for (int i = 1; i <= e; i++)
    {
        result *= 2;
    }
    return result;
}


void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
