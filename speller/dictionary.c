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

// Number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + tolower(c); // hash * 33 + c
    }

    return hash % N;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Get hash index
    unsigned int hashIndex = hash(word);

    // Traverse linked list at that index
    node *curNode = table[hashIndex];
    while (curNode != NULL)
    {
        if (strcasecmp(curNode->word, word) == 0)
        {
            return true;
        }
        curNode = curNode->next;
    }

    return false;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];
    int index = 0;
    char c;
    while (fread(&c, sizeof(char), 1, dict))
    {
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

            // Create a new node for each word
            node *newNode = malloc(sizeof(node));
            if (newNode == NULL)
            {
                return false;
            }
            strcpy(newNode->word, word);
            newNode->next = NULL;

            // Get hash index
            unsigned int hashIndex = hash(word);

            // Insert node into hash table (FIFO)
            if (table[hashIndex] == NULL)
            {
                table[hashIndex] = newNode;
            }
            else
            {
                node *curNode = table[hashIndex];
                while (curNode->next != NULL)
                {
                    curNode = curNode->next;
                }
                curNode->next = newNode;
            }

            // Prepare for next word
            index = 0;
        }
    }

    // Handle the last word if the file does not end with a non-alphabetic character
    if (index > 0)
    {
        word[index] = '\0';
        node *newNode = malloc(sizeof(node));
        if (newNode == NULL)
        {
            return false;
        }
        strcpy(newNode->word, word);
        newNode->next = NULL;

        unsigned int hashIndex = hash(word);

        if (table[hashIndex] == NULL)
        {
            table[hashIndex] = newNode;
        }
        else
        {
            node *curNode = table[hashIndex];
            while (curNode->next != NULL)
            {
                curNode = curNode->next;
            }
            curNode->next = newNode;
        }
    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int wordCount = 0;
    for (int i = 0; i < N; i++)
    {
        node *curNode = table[i];
        while (curNode != NULL)
        {
            wordCount++;
            curNode = curNode->next;
        }
    }
    return wordCount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *curNode = table[i];
        while (curNode != NULL)
        {
            node *tmp = curNode;
            curNode = curNode->next;
            free(tmp);
        }
    }
    return true;
}
