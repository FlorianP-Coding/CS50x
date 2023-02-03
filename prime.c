#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    // excluding 1 as prime
    if (number == 1)
    {
        return false;
    }

    //checking if number is prime
    for (int j = 2; j < number; j++)
    {
        int remainder = number % j;

        if (remainder == 0)
        {
            return false;
        }
    }

    return number;
}
