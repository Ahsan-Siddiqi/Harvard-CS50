// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 262143;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    char lowerWord[strlen(word) + 1];
    for (int i = 0; i < strlen(word); i++)
    {
        lowerWord[i] = tolower(word[i]);
    }
    lowerWord[strlen(word)] = '\0';

    unsigned int index = hash(lowerWord);

    if (table[index] == NULL)
    {
        return false;
    }
    else if (strcmp(lowerWord, table[index]->word) == 0)
    {
        return true;
    }
    else
    {
        node *curNode = table[index];

        while (curNode != NULL)
        {
            if (strcmp(lowerWord, curNode->word) == 0)
                return true;
            curNode = curNode->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 0;
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        hash = (hash * 31 + tolower(word[i])) % N;
        hash = (hash * 17 + (unsigned char) (tolower(word[i]) * tolower(word[(i + 1) % len]))) % N;
    }
    return (unsigned int) hash;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    FILE *dict = fopen(dictionary, "r");

    if (dict == NULL)
        return false;

    char word[LENGTH + 1];
    char c;
    int index = 0;

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

            // insert word
            node *newNode = malloc(sizeof(node));

            if (newNode == NULL)
            {
                fclose(dict);
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
    unsigned int words = 0;

    for (int i = 0; i < N; i++)
    {
        node *curNode = table[i];

        while (curNode != NULL)
        {
            words++;
            curNode = curNode->next;
        }
    }
    return words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *temp = table[i];
            table[i] = table[i]->next;
            free(temp);
        }
    }

    return true;
}
