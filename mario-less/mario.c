#include<cs50.h>
#include <stdio.h>

int main(void)
{
    //get height of the pyramid
    //height must be between 1 and 8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    //print pyramid
    for (int i = 1; i <= height; i++)
    {
        //print spaces (from height-1 to zero)
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }

        //print hashes (from 1 to height)
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        printf("\n");
    }

}