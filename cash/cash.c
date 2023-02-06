#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);
int calculate_coins(int cents, int coin);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

// Ask user to enter the amount of change owed
// Make sure that the input is a non-negative number
int get_cents(void)
{
    int x;
    do
    {
        x = get_int("Change owed: ");
    }
    while (x < 0);
    return x;
}

int calculate_quarters(int cents)
{
    // coin is the value of a quarter
    int coin = 25;
    int num_coins = calculate_coins(cents, coin);
    return num_coins;
}

int calculate_dimes(int cents)
{
    // coin is the value of a dime
    int coin = 10;
    int num_coins = calculate_coins(cents, coin);
    return num_coins;
}

int calculate_nickels(int cents)
{
    // coin is the value of a nickel
    int coin = 5;
    int num_coins = calculate_coins(cents, coin);
    return num_coins;
}

int calculate_pennies(int cents)
{
    // coin is the value of a cent
    int coin = 1;
    int num_coins = calculate_coins(cents, coin);
    return num_coins;
}

int calculate_coins(int cents, int coin)
{
    int i;
    for (i = 0; cents >= coin; i++)
    {
        cents = cents - coin;
    }
    return i;
}