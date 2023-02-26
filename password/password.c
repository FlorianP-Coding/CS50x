// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool lowercase = false, uppercase = false, number = false, symbol = false;
    int l = strlen(password);

    for (int i = 0; i < l; i++)
    {
        if (password[i] >= 97 && password[i] <= 122) // check for lowercase letters
        {
            lowercase = true;
        }
        if (password[i] >= 65 && password[i] <= 90) // check for uppercase letters
        {
            uppercase = true;
        }
        if (password[i] >= 48 && password[i] <= 57) // check for numbers
        {
            number = true;
        }
        if ((password[i] >= 33 && password[i] <= 47) || (password[i] >= 58 && password[i] <= 64) || (password[i] >= 91
                && password[i] <= 96) || (password[i] >= 123 && password[i] <= 126)) // check for symbols
        {
            symbol = true;
        }
    }

    if (lowercase && uppercase && number && symbol)
    {
        return true;
    }
    else
    {
        return false;
    }

}
