#include <cs50.h>
#include <stdio.h>

void print_hashes(int i);
void print_spaces(int y, int z);

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
        //left half
        //print spaces (from height-1 to zero)
        print_spaces(height, i);

        //print hashes (from 1 to height)
        print_hashes(i);

        //space in between two halves
        printf("  ");

        //right half
        //print hashes (from 1 to height)
        print_hashes(i);

        //print spaces (from height-1 to zero)
        //print_spaces (height,i);

        //print new line
        printf("\n");
    }
}

//print hashes
void print_hashes(int x)
{
    for (int k = 0; k < x; k++)
    {
        printf("#");
    }
}

//print spaces
void print_spaces(int y, int z)
{
    for (int j = 0; j < y - z; j++)
    {
        printf(" ");
    }
}