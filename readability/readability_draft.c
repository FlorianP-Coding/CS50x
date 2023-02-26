#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string s);
int count_sentences(string s);
int count_words(string s);

int main(void)
{
    // prompt user for text input
    string sample = get_string("Text sample: ");

    //check if the text does not begin with a space
    if (sample[0] == 32)
    {
        printf("Your text must not begin with a space!\n");
        return 1;
    }
    //printf("Your text sample is: %s\n", sample);


    // determine the length of the string
    int l = strlen(sample);
    //printf("Your text sample consists of %i characters\n", l);


    // count the numbers of letters
    int num_letters = count_letters(sample);
    //printf("Your text consists of %i letters\n", num_letters);


    // count the number of words (still problematic, if multiple spaces are used in front of the last punctuation mark)
    int num_words = count_words(sample);
    //printf("Your text consists of %i words\n", num_words);


    // count the number of sentences (end of a sentence indicated by period (46), exclamation mark (33) or question mark (63))
    int num_sentences = count_sentences(sample);
    //printf("Your text consists of %i sentences\n", num_sentences);

    // calculate Coleman-Liau index
    float L = num_letters * (100.0 / num_words);
    //printf("average number of letters per 100 words: %f\n", L);
    float S = num_sentences * (100.0 / num_words);
    //printf("average number of sentences per 100 words: %f\n", S);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    //printf("The Coleman_Liau index is %f\n", index);

    // round index to the nearest integer
    int rounded_index = round(index);
    //printf("The corresponding rounded index is %i\n", rounded_index);

    // return the grade level according to the Coleman-Liau index
    if (rounded_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (rounded_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", rounded_index);
    }
}

int count_letters(string s)
{
    int l = strlen(s);
    int result = 0;
    for (int i = 0; i < l; i++)
    {
        if (isalpha(s[i]))
        result++;
    }
    return result;
}

int count_sentences(string s)
{
    int l = strlen(s);
    int result = 0;
    for (int i = 0; i < l; i++)
    {
        if ((s[i] == 46 && s[i-1] != 46) || (s[i] == 33 && s[i-1] != 33) || (s[i] == 63 && s[i-1] != 63))
        result++;
    }
    return result;
}

int count_words(string s)
{
    int l = strlen(s);
    int result = 0;
    for (int i = 0; i < l; i++)
    {
        if (s[i] == 32 && s[i-1] != 32)
        result++;
    }
    result++;
    return result;
}
