// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string s);

int main(int argc, string argv[])
{
    // in case the no command-line argument or more than one command-line argument is used
    if (argc != 2)
    {
        printf("The program can only be executed with a single command-line argument\n");
        return 1;
    }
    // in case the user uses a single command-line argument
    else
    {
        printf("%s\n", replace(argv[1]));
    }
}

string replace(string s)
{
    int l = strlen(s); // calculate the length of the word the user has typed in
    for (int i = 0; i < l; i++)
    {
        switch (s[i]) // change the vowels a, e, i, o to numbers
        {
            case 'a':
                s[i] = '6';
                break;
            case 'e':
                s[i] = '3';
                break;
            case 'i':
                s[i] = '1';
                break;
            case 'o':
                s[i] = '0';
                break;
            default:
                s[i] = s[i];
                break;
        }
    }
    return s;
}
