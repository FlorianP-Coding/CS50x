#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Letters of the alphabet
char LETTERS[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
string make_uppercase(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Convert word1 to uppercase letters
    word1 = make_uppercase(word1);
    //printf("%s\n", word1);

    //Convert word2 to uppercase letters
    word2 = make_uppercase(word2);
    //printf("%s\n", word2);

    // Score both words
    int score1 = compute_score(word1);
    //printf("score1 = %i\n", score1);
    int score2 = compute_score(word2);
    //printf("score2 = %i\n", score2);

    // determine the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int k = 0;      // set the counter for scanning the array "LETTERS" to the default value 0
    int l = strlen(word);
    int COUNTER[l];
    int score = 0;

    for (int i = 0; i < l; i++)
    {
        if (word[i] < 65 || word [i] > 90)      // if the character is not a letter assign 0 points
        {
            COUNTER[i] = 0;
        }
        else
        {
            while (word[i] != LETTERS[k])       // scan the array "LETTERS" for the corresponding letter
            {
                k++;        // if the letters do not match continue scanning
            }
            COUNTER[i] = POINTS[k];     // assign the corresponding point to the letter
            k = 0;        // reset the counter for scanning the array "LETTERS" to the default value 0
        }
        // printf("COUNTER [i] = %i\n", COUNTER[i]);
    }

    for (int i = 0; i < l; i++)
    {
        score += COUNTER[i];
    }
    return score;
}

string make_uppercase(string word)
{
    int i = 0;
    while (word[i] != '\0')         // last entry (character) of a string is \0, hence, continue until you encounter \0
    {
        word[i] = toupper(word[i]); // convert current letter to uppercase
        i++;                        // move on to next letter
    }
    return word;
}