#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9
int result[MAX];
int result2 = 0;
int temp2;
int counter2;
int countdown;
int trans, trans2;

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

//array to add things until it is determined whether a cycle exists
bool test[MAX][MAX];

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
            test[i][j] = false;
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
    // TODO
    for (int i = 0; i < candidate_count; i++) {
        //compare strings
        result[i] = strcmp(name, candidates[i]);

        //adding votes
        if (result[i] == 0) {
            ranks[rank] = i;
            result2 = 1;
        }
}
    if (result2 == 0) {
        return false;
    }
    else {
        return true;
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++) {
        for (int j = i+1; j < candidate_count; j++) {
                preferences[ranks[i]][ranks[j]]++;
        }
   }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO: tweak.
    for (int i = 0; i< candidate_count; i++) {
        for (int j = i+ 1; j< candidate_count; j++) {
            if(preferences[i][j] != preferences[j][i] && i != j) {

                if(preferences[i][j] > preferences[j][i]) {
                pairs[i].winner = i;
                pairs[i].loser = j;
                pair_count ++;
                }
                else if (preferences[i][j] < preferences[j][i]) {
                    pairs[i].winner = j;
                    pairs[i].loser = i;
                    pair_count ++;
                }
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    int diff = 0;
    int diff1 = 0;
    int counter = -1;

        pair temp;

        while (counter != 0)  {
        for (int j = 0; j < pair_count; j++) {
        counter = 0;

        diff = preferences[pairs[j].winner][pairs[j].loser] - preferences[pairs[j].loser][pairs[j].winner];
        diff1 = preferences[pairs[j + 1].winner][pairs[j + 1].loser] - preferences[pairs[j + 1].loser][pairs[j + 1].winner];

        //where swap takes place, pushing the pairs with lower margin of victory to the right of the array
        if (diff < diff1) {
        temp = pairs[j];
        pairs[j] = pairs[j + 1];
        pairs[j + 1] = temp;

        counter++;
        }
        }
}
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO: Faulty, fix using recursion.
    for(int i = 0; i< candidate_count; i++) {
        for (int j = 0; j < candidate_count; j++) {
            if (test[i][j] == false) {
                trans++;
                if (trans == candidate_count) {
                    trans2 = trans;
                }
            }
        }
        trans = 0;
    }
    printf("%d", trans2);
    printf("%d", candidate_count);
    if(trans2 != candidate_count) {

        for (int i = 0; i < candidate_count-1; i++) {
        locked[pairs[i].winner][pairs[i].loser] = true;
    }
    }
    else {
        for (int i = 0; i < candidate_count; i++) {
        locked[pairs[i].winner][pairs[i].loser] = true;
    }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO: Alter to account for ties
    printf("%s\n", candidates[pairs[0].winner]);
    return;
}