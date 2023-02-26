#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // if the users does not enter the correct number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // determine the length of the command-line argument
    int l_argv = strlen(argv[1]);

    // if the user does not enter a valid key
    if (l_argv != 26)        // if the key does not consist of 26 characters
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < l_argv; i++)        // if the key does not consists of letters only
    {
        if (!(isalpha(argv[1][i])))
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }

    for (int i = 0; i < l_argv; i++)        // if the same letter appears more than once in the key
    {
        for (int j = 0; j < i; j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must contain 26 different characters, i.e. a letter does not appear more than once.\n");
                return 1;
            }
        }
    }


    // make an array consisting of the letters of the alphabet (needed for counter j)
    char alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    // promt user to type the plaintext
    string plaintext = get_string("plaintext:  ");
    int l_plain = strlen(plaintext);        // determine the length of the plaintext

    // print "ciphertext" and do NOT print a new line (letters of the ciphertext are added)
    printf("ciphertext: ");

    // substitute letters in the plaintext according to the key (argv)
    for (int i = 0; i < l_plain; i++)       // iterate through all characters from the plaintext
    {
        if (!(isalpha(plaintext[i])))       // characters other than letters are not substituted
        {
            printf("%c", plaintext[i]);
        }
        else        // letters are substituted according to the key
        {
            if (islower(plaintext[i]))      // lowercase letters remain lowercase
            {
                for (int j = 0; j < 26; j++)        // iterate through the alphabet
                {
                    if (plaintext[i] == tolower(alphabet[j]))       // determine counter j
                    {
                        printf("%c", tolower(argv[1][j]));      // substitute letter in plaintext by j-th letter from the key
                    }
                }
            }
            else if (isupper(plaintext[i]))      // uppercase letters remain lowercase
            {
                for (int j = 0; j < 26; j++)        // iterate through the alphabet
                {
                    if (plaintext[i] == toupper(alphabet[j]))       // determine counter j
                    {
                        printf("%c", toupper(argv[1][j]));      // substitute letter in plaintext by j-th letter from the key
                    }
                }
            }
        }
    }

    printf("\n");

    return 0;
}