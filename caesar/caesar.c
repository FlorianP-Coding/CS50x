#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // if the program is executed without any command-line arguments
    // or with more than one command-line argument, print  an error message
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int l_argv = strlen(argv[1]);        // determine the length of the command-line argument

    // If any of the characters of the command-line argument is not a decimal digit,
    // print an error message
    for (int i = 0; i < l_argv; i++)
    {
        if (argv[1][i] < 48 || argv[1][i] > 57)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // determine the actual shift if the user enters a number greater than 26
    int key = atoi(argv[1]) % 26;     // atoi() converts string-numbers to int-numbers

    // ask user to type in plaintext
    string plaintext = get_string("plaintext:  ");
    int l_plaintext = strlen(plaintext);        // determine the length of the plaintext

    //print ciphertext
    printf("ciphertext: ");     // do not print a new line!

    // convert plaintext to ciphertext
    int dec_p;
    for (int i = 0; i < l_plaintext; i++)
    {
        int dec_c;
        dec_p = plaintext[i];

        if (isalpha(plaintext[i]))      // only alphanumerical characters are shifted
        {
            if (islower(plaintext[i]))      // if the character is a lowercase letter
            {
                int to_end_lower = 122 - plaintext[i];      // distance to end of lowercase letters in ASCII
                // to make sure that we only shift through lowercase letters

                if (to_end_lower >= key)
                {
                    dec_c = dec_p + key;
                    printf("%c", dec_c);
                }
                else
                {
                    dec_c = 96 + (key - to_end_lower);
                    printf("%c", dec_c);
                }
            }
            else if (isupper(plaintext[i]))     // same here for uppercase letters
            {
                int to_end_upper = 90 - plaintext[i];
                if (to_end_upper >= key)
                {
                    dec_c = dec_p + key;
                    printf("%c", dec_c);
                }
                else
                {
                    dec_c = 64 + (key - to_end_upper);
                    printf("%c", dec_c);
                }
            }
        }
        else
        {
            printf("%c", dec_p);
        }
    }
    printf("\n");
}