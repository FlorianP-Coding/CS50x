#include <cs50.h>
#include <stdio.h>

int get_years(int start, int end);

int main(void)
{
    // TODO: Prompt for start size
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    // TODO: Print number of years
    printf("Years: %i\n", get_years(start_size, end_size));
}

// TODO: Calculate number of years until we reach threshold
int get_years(int start, int end)
{
    // setting up counter
    int years = 0;

    // algorithm
    for (int i = start; i < end; years++)
    {
        i = i + i / 3 - i / 4;
    }
    return years;
}
