#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];
int voter_count;

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

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

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
    voter_count = get_int("Number of voters: ");

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
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)

    {
        if (strcmp (name, candidates[i]) == 0)

        {
            ranks[rank] = i;

            rank++;

            return true;
        }


    }

    // TODO
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{


    for (int a = 0; a < candidate_count; a++)

    {

        for (int b = a + 1; b < candidate_count; b++)

        {


                preferences[ranks[a]][ranks[b]]++;


            }
        }


    // TODO
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{

    int y = 0;
    int z = 0;
    int arr[z];

    for (int m = 0; m < candidate_count; m++)

    {
        for (int n = 0; n < candidate_count; n++)

        {
            if ( preferences[m][n] >= 0)

            {
                y = preferences[m][n];
                z++;

                arr[z] = y;
            }

        }
    }

    int k = 0;

    for (int i = 0; i < candidate_count; i++)

    {
        for (int j = i + 1; j < candidate_count; j++)

        {
            if (arr[i] == arr[j])

            {
                k++;
            }
        }
    }

    int x = candidate_count;

    pair_count = (((x - 1) * x) / 2) - k;


    // TODO
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    return;
}

