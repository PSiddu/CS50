// Implements a dictionary's functionality

#include <stdbool.h>
#include "dictionary.h"
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

node *new_node;
node *temp_node;

//Keeping wordcount
int wordcount = 0;
int counter = 0;

// Number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    unsigned int hashnum = hash(word);

    node *check_node = table[hashnum];

    while (true)
    {
        if (check_node == NULL)
        {
            return false;
        }

        else if (strcasecmp(check_node->word, word) == 0)
        {
            return true;
        }

        else
        {
            check_node = check_node -> next;
        }
    }
}

// Hashes word to a number (Source: http://www.cse.yorku.ca/~oz/hash.html)
unsigned int hash(const char *word)
{
        unsigned long hash = 5381;
        int c;

        while ((c = *word++))
            hash = ((hash << 5) + hash) + tolower(c); /* hash * 33 + c */

        return (hash % N);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //Opening dictionary file
    FILE *file = fopen(dictionary, "r");

    //returns error if the file is not valid
    if (file == NULL)
    {
        return false;
    }

    //creating array for word to be stored
    char word[LENGTH + 1];

    //While reading strings from file, loading words into hash table
    while(fscanf(file, "%s", word) != EOF)
    {
        //creating a new node
        new_node = malloc(sizeof(node));
        counter ++;

        //checking if return value is NULL
        if (new_node == NULL)
        {
        return false;
        }

        //copying word into array using strcpy
        strcpy(new_node->word, word);
        new_node -> next = NULL;

        //Hashing the word
        unsigned int hashnum = hash(word);

        //if current bucket is empty, add the word to it and set the pointer to next item to NULL
        if (table[hashnum] == NULL)
        {
            table[hashnum] = new_node;
            wordcount++;
        }
        //if there is already one or more words in the current bucket, set the pointer to the rest of the linked list to the new word/node, then add that node into the bucket.
        else
        {
        temp_node = malloc(sizeof(node));
        temp_node = table[hashnum];
             while (true)
            {
               if (temp_node -> next == NULL)
                {
                    temp_node -> next = new_node;
                    wordcount++;
                }
                // update pointer to move along the linked list
                temp_node = temp_node -> next;

            }
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordcount;
}

// Unload is responsible for freeing up any memory allocated througout the running of the program
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        free(cursor);
    }
    return true;
}