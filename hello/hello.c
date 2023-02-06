#include<cs50.h>
#include<stdio.h>

int main(void)
{
    //ask for name
    string name =  get_string("What's your name? ");

    //greet user
    printf("Hello, %s!\n", name);
}