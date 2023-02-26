// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
// // BUBBLE SORT:
// void sort_cities(void)
// {
//     // Add your code here
//     int c = 1;
//     while (c > 0)
//     {
//         c = 0;
//         for (int i = 0; i < NUM_CITIES - 2; i++)
//         {
//             if (temps[i].temp < temps[i + 1].temp)
//             {
//                 avg_temp x = temps[i];      // values are temporarily stored in another variable
//                 avg_temp y = temps [i + 1];     // values are temporarily stored in another variable
//                 temps[i] = y;       // swap position
//                 temps[i + 1] = x;       // swap position
//                 c++;
//             }
//         }
//     }
// }

// SELECTION SORT:
void sort_cities(void)
{
    // Add your code here
    avg_temp pivot;
    avg_temp max;
    int memory;

    for (int i = 0; i < NUM_CITIES; i++)        // iterate through list
    {
        pivot = temps[i];
        max = temps[i];
        memory = 0;

        for (int j = i + 1; j < NUM_CITIES; j++)    // compare i-th element to the remaining elements
        {
            if (temps[j].temp > max.temp)
            {
                max = temps[j];     // remember current value for max
                memory = j;     // remember current index for max
            }
        }

        if (memory != 0)        // only swap if you found a value which is highter than the pivot element
        {
            temps[memory] = pivot;
            temps[i] = max;
        }
    }
}
