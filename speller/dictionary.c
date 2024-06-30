// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
// search function
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return (toupper(word[0]) - 'A') + (toupper(word[strlen(word)]) - 'A') + (toupper(word[strlen(word)/2]) - 'A');
}

// Loads dictionary into memory, returning true if successful, else false
// insert function
bool load(const char *dictionary)
{

    for (int i = 0; i < N; i++) {
        table[i] = NULL;
    }

    FILE *dict = fopen(dictionary, "r");

    if (dict == NULL) return false;

    char word[LENGTH + 1];
    char c;
    int index;

    while (fread(&c, sizeof(char), 1, dict)) {
        if (isalpha(c) || (c == '\'' && index > 0))
        {
            // Append character to word
            word[index] = c;
            index++;
        }
        else if (index > 0)
        {
            // Terminate current word
            word[index] = '\0';

            //insert word
            node *newNode = malloc(sizeof(node));
            strcpy(newNode->word, word);
            newNode->next = NULL;
            unsigned int hashIndex = hash(word);
            if (table[hashIndex] == NULL) {
                table[hash(word)] = newNode;
            } else {
                node *curNode = table[hashIndex]->next;
                while (curNode->next != NULL) {
                    curNode = curNode->next;
                }
                curNode->next = newNode;
            }

            // Prepare for next word
            index = 0;
        }
    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
// delete function
bool unload(void)
{
    // TODO
    return false;
}
