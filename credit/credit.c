#include <cs50.h>
#include <stdio.h>

long powers_of_ten(int e);
int get_first_two_digits(long x, int y);
int get_first_digit(long x, int y);
int get_checksum(long x, int y);

int main(void)
{
    // input: get credit card number
    long card_number = get_long("Number: ");


    // calculate the number of digits of the credit card number
    long cut_number = card_number;
    int number_of_digits;
    for (number_of_digits = 0; cut_number > 0; number_of_digits++)
    {
        cut_number = cut_number / 10;
    }


    // determine first two digits of the credit card number
    int first_two_digits = get_first_two_digits(card_number, number_of_digits);
    //printf("first two digits: %i \n", first_two_digits);


    // determine first digit of the credit card number
    int first_digit = get_first_digit(card_number, number_of_digits);
    //printf("first digit: %i \n", first_digit);


    // calculate the checksum
    int checksum = get_checksum(card_number, number_of_digits);
    //printf("checksum: %i\n", checksum);


    // check if the checksum is valid (i.e. if its last digit is zero)
    int valid_checksum;
    if (checksum % 10 == 0)
    {
        valid_checksum = true;
    }


    // determine the type of credit card
    // check if it is an AMEX card
    if (number_of_digits == 15 && valid_checksum && (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
    }

    // check if it is a VISA card
    else if ((number_of_digits == 13 || number_of_digits == 16) && valid_checksum && first_digit == 4)
    {
        printf("VISA\n");
    }
    
    // chek if it is a MASTERCARD
    else if (number_of_digits == 16 && valid_checksum && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        printf("MASTERCARD\n");
    }

    // otherwise we consider the card as invalid
    else
    {
        printf("INVALID\n");
    }
}


// create a function that calculates the powers of ten
long powers_of_ten(int e)
{
    long k = 1;
    for (int i = 1; i <= e; i++)
    {
        k = k * 10;
    }
    return k;
}


// calculate checksum
int get_checksum(long x, int y)
{
    int i;
    int k = 0;
    long remainder1;
    long remainder2;
    int digit1;
    int digit1_times_two;
    int digit2;
    int sum1 = 0;
    int sum2 = 0;

    for (i = 0; k <= y; k = k + 2)
    {
        // calculate sum1: every second digit multiplied by two starting with the second to last ...
        // identify the digit
        remainder1 = x % powers_of_ten(k + 2);
        digit1 = remainder1 / powers_of_ten(k + 1);
        // multiply the digit by 2
        digit1_times_two = 2 * digit1;
        // add up the digits
        // the variable digit_times_two has to be added up digit by digit if it consists of two digits (when variable digit > 4)
        sum1 = sum1 + digit1_times_two / 10 + digit1_times_two % 10;

        // calculate sum2: the remaining digits are added up
        // identify the digit
        remainder2 = x % powers_of_ten(k + 1);
        digit2 = remainder2 / powers_of_ten(k);
        // add up the digits
        sum2 = sum2 + digit2;
    }

    // calculate checksum
    int sum = sum1 + sum2;
    return sum;
}

// function that determines the first to digits of the credit card number
int get_first_two_digits(long x, int y)
{
    int first_two_digits = x / powers_of_ten(y - 2);
    return first_two_digits;
}

// function that determines the first digit of the credit card number
int get_first_digit(long x, int y)
{
    int first_digit = x / powers_of_ten(y - 1);
    return first_digit;
}