// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

//variables
unsigned int word_count;
unsigned int hash_value;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    hash_value = hash(word);
    node* cursor = table[hash_value];                   //use hash value to access the linked list

    while (cursor != 0)

    {
        if(strcasecmp(word, cursor->word) == 0)         //if word is found in linked list, return true

        {
            return true;
        }
        cursor = cursor->next;                          //else move cursor to next node to compare next word in linked list
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long total = 0;
    for(int i = 0; i < strlen(word); i++)       //credit to CS50 Guide by Anvea for hash function

    {
        total += tolower(word[i]);
    }

    return total % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    //create a pointer file to store the address if the data read from dictionary

    FILE *file = fopen(dictionary, "r");        //dictionary replaces the actual dictionary files. dictionary is defined in speller.c on lines 15 and 36

    if (file == NULL)

    {
        return false;       //if file cannot be read, return false
    }

    char word_copied[LENGTH + 1];       //create a character array 'word_copied' to store the words

    while (fscanf(file, "%s", word_copied) != EOF)     //fscanf prints the data from pointer 'file' to into variable 'word_copied'. the while loop keeps doing that until it reaches end of file (EOF)

    {
        node *n = malloc(sizeof(node));     //'n' is a pointer to the struct 'node'. malloc creates a memory block for node and returns the address of the memory block in 'n'

        if (n == NULL)                      //if memory points to nothing, return false

        {
            return false;
        }

        strcpy(n->word, word_copied);           //strcpy copies the word from 'word_copied' into the 'word' field of the struct node (n.word)
        hash_value = hash(word_copied);         //hash_value is an int to store the return value of the hash function. This variable might need to be declared outside the function
        n->next = table[hash_value];            //table is a struct of type node that updates the 'next' field of the struct node (n.next)
        table[hash_value] = n;
        word_count++;                           //count the number of words
    }

    fclose(file);                               //close the file

    return true;                                //end the function
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO

    if(word_count > 0)

    {
        return word_count;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO

    for (int i = 0; i < N; i++)                 //create loop to iterate through different linked lists

    {
        node *cursor = table[i];                //create cursor that will point to each node
        while (cursor)

        {
            node *temp = cursor;                //temporary node points to next node
            cursor = cursor->next;              //cursor points to temporary node to retain memory address of linked list
            free(temp);                         //free temp
        }

        if (cursor == NULL && i == N-1)

        {
            return true;
        }
    }
    return false;
}
