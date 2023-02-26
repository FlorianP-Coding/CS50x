#include <cs50.h>
#include <stdio.h>
#include <strings.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

// array containing the strength (weight) of each victory
// int weight_vic[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

// additional funktion
int weight_vic(int i, pair array[]);
bool check(int x, int y);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();

// for (int i = 0; i < pair_count; i++)
// {
//     printf("winner %i, loser %i\n", pairs[i].winner, pairs[i].loser);
// }

    sort_pairs();

// for (int i = 0; i < pair_count; i++)
// {
//     printf("winner %i, loser %i\n", pairs[i].winner, pairs[i].loser);
// }


    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcasecmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;       // i is treated as placeholder for a name on the list of candidates
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    // iterate through the ranks array ()
    for (int i = 0; i < candidate_count; i++)
    {
        // the candidate on that rank wins over the preceding candidates
        for (int j = i +1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    // consider preferences[i][j] a matrix
    // interate through the lines
    for (int i = 0; i < candidate_count; i++)
    {
        // iterate through the rows
        for (int j = i; j < candidate_count; j++)
        {
            // if correspoding entries are different, add a pair
            if (!(preferences[i][j] == preferences[j][i]))
            {
                // determine the winner and the loser of this pairing
                if (preferences[i][j] > preferences[j][i])
                {
                    pairs[pair_count].winner = i;
                    pairs[pair_count].loser = j;
                    // weight_vic[pair_count] = preferences[i][j] - preferences[j][i];
                }
                else
                {
                    pairs[pair_count].winner = j;
                    pairs[pair_count].loser = i;
                    // weight_vic[pair_count] = - (preferences[i][j] - preferences[j][i]);
                }

                pair_count++;
            }
        }
    }
    return;
}

// function that determines the strength (weight) of a victory
int weight_vic(int i, pair array[])
{
    int result = preferences[array[i].winner][array[i].loser];
    return result;
}

// Sort pairs in decreasing order by strength of victory
// use selection sort
void sort_pairs(void)
{
    // TODO

    pair pivot;
    int max;
    pair strongest;
    int memory;

    for (int i = 0; i < pair_count; i++)        // iterate through list pairs
    {
        pivot = pairs[i];
        max = weight_vic(i, pairs);
        memory = 0;

        for (int j = i + 1; j < pair_count; j++)    // compare i-th element to the remaining elements
        {
            if (weight_vic(j, pairs) > max)
            {
                max = weight_vic(j, pairs);     // remember current value for max
                strongest = pairs[j];       // remember corresponding value for the strongest victory
                memory = j;     // remember current index for max
            }
        }

        if (memory != 0)        // only swap if you found a value which is highter than the pivot element
        {
            pairs[memory] = pivot;
            pairs[i] = strongest;
        }
    }
}


void lock_pairs(void)
{

    for (int i = 0; i < pair_count; i++)
    {
        if (check(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
            printf("locked: %s, %s\n", candidates[pairs[i].winner], candidates[pairs[i].loser]);
        }
    }
}

bool check(int x, int y)
{
    if (x == y)
    {
        return false;
    }

    for (int j = 0; j < pair_count; j++)
    {
        if (locked[y][pairs[j].loser])
        {
            if (check (x, pairs[j].loser))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

// bool check(int i, int x)
// {
//     if (i == 0)
//     {
//         return true;
//     }

//     for (int j = 0; j < i; j++)
//     {
//         if (locked[pairs[i].loser][pairs[j].loser])
//         {
//             if (pairs[j].loser == x)
//             {
//                 return false;
//             }
//             if (check (j, x))
//             {
//                 return true;
//             }
//             else
//             {
//                 return false;
//             }
//         }
//     }

//     return true;
// }


// Print the winner of the election
void print_winner(void)
{
    // TODO
    // find the start which is not an end
    bool success;
    for (int i = 0; i < pair_count; i++)
    {
        for (int j = 0; j < pair_count; j++)
        {
            if (locked[pairs[j].winner][pairs[i].winner])
            {
                success = false;
                break;
            }
            success = true;
        }
        if (success)
        {
            printf("%s\n", candidates[pairs[i].winner]);
            break;
        }
    }
    return;
}