#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main (void)
{
    // ask user to enter an integer n
    int number = get_int("starting number: ");

    // determine the number of steps to get to 1
    int result = collatz(number);
    printf("It needs %i steps to get to 1\n", result);
}

int collatz(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n % 2 == 0)
    {
        return 1 + collatz(n / 2);
    }
    else
    {
        return 1 + collatz((3 * n) +1);
    }
}