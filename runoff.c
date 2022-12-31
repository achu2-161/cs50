#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100                                                                      //declaration of max number of voters stored in int variable MAX_VOTERS = 100
#define MAX_CANDIDATES 9                                                                    //declaration of max number of candidates stored in int variable MAX_CANDIDATES = 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];                                                //int array variable preference storing every vote - array contains voter index (i) and preference (j) eg preferences[0][1] = 2 means voter 0 has selected preference 1 (or rank 1) as candidate 2

// Candidates have name, vote count, eliminated status
typedef struct                                                                              //declaration of a data structure storing:
{
    string name;                                                                            //string variable name to store name of candidate
    int votes;                                                                              //int variable votes to store how many votes candidates received - initially 0th preference votes and will keep being updates as runoff run and lower preferences are counted
    bool eliminated;                                                                        //bool variable eliminated to store whether a candidate has been eliminated
}
candidate;                                                                                  //name of data structure is candidate

// Array of candidates
candidate candidates[MAX_CANDIDATES];                                                       //declaration of array candidates containing the data structure candidate. the array takes up to MAX_CANDIDATES items = 9

// Numbers of voters and candidates
int voter_count;                                                                            //declaration of int variable voter_count storing number of voters - will be input by user later using a get_int function
int candidate_count;                                                                        //declaration of int variable candidate_count storing number of candidates - is obtained from argc - 1 from CLI (argc = number of candidates + name of program)

// Function prototypes
bool vote(int voter, int rank, string name);                                                //declaration of function vote returning taking 3 variables (int voter [index of voter], int rank [rank that voter is voting on], and string name [name of candidate]). Returns bool if vote is valid or not
void tabulate(void);                                                                        //declaration of function tabulate taking no value - takes global variables and returns no value but updates global variables. function allocates votes to each candidates in data struct
bool print_winner(void);                                                                    //declaration of function print_winner taking no value takes and updates global variables and returns a bool *???*
int find_min(void);                                                                         //declaration of function find_min taking no value taking no value *presumably to determine which candidate has the smallest number of first preference votes*
bool is_tie(int min);                                                                       //declaration of functin is_tie taking int min variabls *not sure where from* *presumably to determine if there are ties is the minimums*
void eliminate(int min);                                                                    //declaration of function eliminate taking int min variable *not sure where from* * presumably to eliminate the candidate that has the smallest first preference votes*

int main(int argc, string argv[])                                                           //declaration of main function. function takes 2 variables, int argc (number of terms in CLI) and string argv (name of the candidates written in CLI)
{
    // Check for invalid usage
    if (argc < 2)                                                                           //condition to check if argc is less than 2 (meaning only one candidate) - argc = 2 means name of program + name of one candidate
    {
        printf("Usage: runoff [candidate ...]\n");                                          //if above condition is met, print error message and return 1 to end the program
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;                                                             //declaration of int variable candidate_count to store number of candidates entered in CLI
    if (candidate_count > MAX_CANDIDATES)                                                   //if number of candidates entered in CLI is larger than the number of max candidates (MAX_CANDIDATES = 9),
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);                     //print error message and return 2 to end the program
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)                                               //for loop to cycle through all candidates to populate the data structure candidates.
    {
        candidates[i].name = argv[i + 1];                                                   //for loop simply takes the namne of the candidates from string argv (from CLI) and stores in structure.
        candidates[i].votes = 0;                                                            //initialises number of votes to 0
        candidates[i].eliminated = false;                                                   //initialises elimination status as false
    }

    voter_count = get_int("Number of voters: ");                                            //initialisation of int variable voter_count. promp for the user to input number of voters. value entered by user stored in variable voter_count
    if (voter_count > MAX_VOTERS)                                                           //condition to assess maximum number of voters does not exceed 100
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);                             //if above condition is met, print error message and return 3 to end program
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)                                                   //nested loops to cycle through every candidate and every voter
    {                                                                                       //outside loop cycles through every voter using counter i

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)                                           //inside loop cycles through every candidate using counter j
        {
            string name = get_string("Rank %i: ", j + 1);                                   //declaration of string variable string. get_string prompts the user to enter name of candidate at each preference.
                                                                                            //"rank %i: ", j + 1 prints in CLI value of rank j. as j increases loop keeps asking user to enter name for each preference. %i here means get_int is looking for an integer value to print (j + 1) and does not refer to coutner i in outside loop
            // Record vote, unless it's invalid
            if (!vote(i, j, name))                                                          //vote function (declared earlier, defined later) used to keep track of all votes. takes 3 variables (candidate j, voter i, and candidate name name)
            {
                printf("Invalid vote.\n");                                                  //if function vote returns false, print error message and return 4 to end the program
                return 4;
            }
        }

        printf("\n");                                                                       //after nested loop has run voter_count * candidate_count times, print new line
    }

    // Keep holding runoffs until winner exists
    while (true)                                                                            //while loop used to run runoff. *presumably true means runoff is necessary and a function will update this to false when a winner is found*
    {
        // Calculate votes given remaining candidates
        tabulate();                                                                         //tabulate function is called to add up all the ballots preferences and add top preference to each candidate fro candidate struct. tabulate function will be called several times if runoff is required.
                                                                                            //tabulate function has a condition to add lower preference to candidates when candidates are eliminated and runoff necessary. *presumably later function will update candidate struct eliminate lowest candidate
        // Check if election has been won
    bool won = print_winner();                                                              //function print_winner is called. bool variable won stores the value that function print_winner returns (line211 / line 215)
    if (won)                                                                                //if int won is true (print_winner function has printed name of winner and returned true)
        {
            break;                                                                          //program ends
        }
                                                                                            //if int won is false (print_winner has failed to identify and winner, i.e. not printed anything and returned false) main function continues running
        // Eliminate last-place candidates
        int min = find_min();                                                               //function find_min is called. int variable min stores value that function find_min returns (as smallest, line240). function find_min is used to identify what is the smallest number of vote across all candidates
        bool tie = is_tie(min);                                                             //function is_tie is called. bool variable tie stores value that fuction is_tie returns. is_tie takes argument min, which was obtained from previous function

        // If tie, everyone wins
        if (tie)                                                                            //if bool tie is true (function is_tie returned true), line105 to line114 run
        {
            for (int i = 0; i < candidate_count; i++)                                       //for loop used to cycle all candidates
            {
                if (!candidates[i].eliminated)                                              //if statement to discard candidates already eliminated
                {
                    printf("%s\n", candidates[i].name);                                     //print the name of candidate that has tied
                }
            }                                                                               //loop ensures that all candidates who have tied are printed
            break;                                                                          //once all tied candidates are printed, break to end the program
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);                                                                     //function eliminate is called, taking min as a parameter (from line100). function is used to eliminate candidates with minimum votes.
                                                                                            //function only runs if runoff necesary i.e. function will only run if there are no majority winners and no ties (if there are, program breaks on lines 96 and 113 respectively)
        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)                                           //since runoff needed vote coutners are reset to zero to be recalculated, taking into account elimination from eliminate function (line117) for loop to cycle through all candidates
        {
            candidates[i].votes = 0;                                                        //vote count for each candidate is reset to 0
        }
    }
    return 0;
}

// Record preference if vote is valid


bool vote(int voter, int rank, string name)                                     //definition of function vote. from main (line76), i is parsed into voter, j is parsed into rank and name is parsed into name
{
    for (int i = 0; i < candidate_count; i++)                                   //for loop to make sure that the name parsed from main is compared to the names of all candidates

    {
        if ((strcmp(name, candidates[i].name) == 0))                            //if name supplied by user in main (parsed as name) matches the name of candidate i (== 0),

        {

            preferences[voter][rank] = i;                                       //the preference array is updated. eg if preferences[1][2] = 3 means the index of the voter (voter 1) and their preference (rank 2) is matched to the candidate (3)

            return true;                                                        //returns true to end the function

        }
    }


    // TODO
    return false;                                                               //otherwise will return false, which will trigger an error message in main (line 78), and return 4 to end the program (line 79)
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)                                                             //definition of function tabluate which will compile all the votes in the data struct. function takes no vaulue and returns no value, but uses and updates global variables
{
    // TODO

    int total = 0;                                                              //initialisation of int variable total to calculate total number of votes (voters * candidates) - will probably not use in this functin
                                                                     //initialisation of int variable k = 0. k will be used to increment the preference in case a candidate is eliminated and the ballots with that candidate's top preference needs to be ignored

    for (int i = 0; i < voter_count; i++)                                       //nested loops to go through all voters and all candidates
                                                                                //outside loop cycles through all voters using counter i
    {
        for (int j = 0; j < candidate_count; j++)                               //inside loop cycles through all candidates using counter j

        {
            int k = 0;                                                            //for each looop that is run, total is incremented by 1 (again, not sure to be used in this function)

            if (candidates[j].eliminated == false)                              //condition to check is candidate has been eliminated. information is taken from data struct. in the first round, all candidates are still in the race. *presumably another function will update this global variable later

            {
                if (preferences[i][k] == j)                                     //if candidate still in race: if the vote for candidate preference k (initially 0 since all candidates still in the race) from voter i corresponds to candidate j,

                {
                    candidates[j].votes++;                                      //vote count for candidate j is incremented by 1
                }
                                                                                //if vote from voter i does not correspond to candidate j, no global variabls is incremented
            }

            else if (candidates[j].eliminated == true)                                                                //if candidate is eliminated

            {
                k++;                                                            //variable k is incremented so that the next preference on ballots with eliminated candidates set as higher preference is checked

                if (preferences[i][k] == j)                                     //if vote for candidate preference k (not 0 anymore since candidate has been eliminated at some point and k has been incremented) from voter i corresponds to candidate j

                {
                    candidates[j].votes++;                                      //vote count for candidate h is incremented by 1
                }                                                               //if vote from voter i does not correspond to candidate j, no global variable is incremented
            }
                                                                                //internal loop goes to the next candidate
        }
                                                                                //when top preference of voter is compared against each candidate, outer loop cycles to next voter
    }

    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)                                                         //definition of function print_winner that takes no argument (uses global variables updated in previous functions) and returns a bool. function checks if there is a majority (>50% of votes)
{
    // TODO

    for(int i = 0; i < candidate_count; i++)                                    //for loop to cycle through all the candidates using counter i

    {

        if (candidates[i].votes > voter_count/2)                                //if candidate i has a number of votes that is greater than half the total number of voters (simple majority) and prints name of winner if majority if found

        {
            printf("%s\n", candidates[i].name);                                 //prints name of candidate i
            return true;                                                        //function returns true
        }
    }

    return false;                                                               //if no candidate has simple majority, function returns false
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)                                                              //definition of function find_min that takes no argument (uses global variables updated previously) and returns an int, which will correspond to the number of votes the lowest candidate has
{
    // TODO

    int smallest = candidates[0].votes;                                         //declaration of int variable minimum to store smallest number of votes. smallest is initialised as being number of votes for candidate 0

    for (int i = 0; i < candidate_count; i++)                                   //for loop to cycle through all the candidates using counter i

    {
        if (candidates[i].eliminated == false)                                   //if statement to only run through candidates that are still in the race (not eliminated)

        {
            if (candidates[i].votes < smallest)                                 //if number of votes for candidate i is smaller than value stored in smallest (function will always return false in first loop)

            {
                smallest = candidates[i].votes;                                 //int variable monimum is updates with new value. loop cycles through all candidates until lowest votes of any candidate is found
            }
        }

    }

    return smallest;                                                            //when the loop is complete, return smallest to main program
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)                                                            //definition of function is_tie which takes int variable min (from main in previous function) and returns a bool if a tie is found
{
    // TODO

    int a = 0, b = 0;                                                           //initialisation of int variables a and b. a will track how many candidates are still in the race (not eliminates). b will track how many candidates have the minimum vote

    for (int i = 0; i < candidate_count; i++)                                   //for loop cycling through all candidates using i as counter

    {
        if (candidates[i].eliminated == false)                                  //if statement used to check is candidate i is still in the race (not eliminated)

        {
            a++;                                                                //if candidate i is not eliminated, increment a by 1
        }
    }

    for (int j = 0; j < candidate_count; j++)                                   //for loop cycling through all candidates using j as counter

    {
        if (candidates[j].votes == min)                                         //if statement to compare candidate j's votes against minimum votes

        {
            b++;                                                                //if candidate j's vote equals minimum votes, increment b by 1
        }
    }

    if (a == b)                                                                 //if statement used to check if number of remaining candidates equals number of candidates with minimum votes

    {
        return true;                                                            //if all remaining candidates have minimum votes, return true
    }


    return false;                                                               //otherwise return false
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)                                                         //definition of function eliminate, that takes min as a parameter and updates global variables. function eliminates candidate with minimum vote
{
    // TODO

    for (int i = 0; i < candidate_count; i++)                                   //for loop to cycle through all candidates using i as a counter

    {
        if (candidates[i].votes == min)                                         //if statement to compare candidate vote to minimum vote

        {
            candidates[i].eliminated = true;                                    //if candidate vote same as minimum vote, elimination status is updated (candidate is eliminated)
        }

    }

    return;                                                                     //return to main function
}