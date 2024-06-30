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
const unsigned int N = 262143;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
// search function
bool check(const char *word)
{
    // TODO
    char lowerWord[strlen(word) + 1];
    for (int i = 0; i < strlen(word); i++) {
        lowerWord[i] = tolower(word[i]);
    }
    lowerWord[strlen(word)] = '\0';


    unsigned int index = hash(lowerWord);
    //printf("lowerWord: %s - table[index]->word: %s\n", lowerWord, table[index]->word);
    if(table[index] == NULL) {
        return false;
    } else if (strcmp(lowerWord, table[index]->word) == 0) {
        return true;
    } else {
        node *curNode = table[index];

        while (curNode != NULL) {

            if (strcmp(lowerWord, curNode->word) == 0) return true;

            //printf("lowerWord: %s\ncurnode->word: %s\n", lowerWord, curNode->word);

            curNode = curNode->next;
        }


    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //printf("word: %s", word);
    unsigned long hash = 5381;
    int c;

    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + tolower(c); // hash * 33 + c
    }
    //printf(" - hash: %lu\n", hash % N);

    return hash % N;
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
    int index = 0;

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

            if (newNode == NULL)
            {
                fclose(dict);
                return false;
            }

            strcpy(newNode->word, word);
            newNode->next = NULL;

            unsigned int hashIndex = hash(word);
            if (table[hashIndex] == NULL) {
                table[hashIndex] = newNode;
            } else {
                node *curNode = table[hashIndex];

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
    unsigned int words;
    for (int i = 0; i < sizeof(table); i++) {
        node *curNode = table[i];

        if (curNode != NULL) words++;

        while (curNode->next != NULL) {
            curNode = curNode->next;
            words++;
        }
    }
    return (words > 0) ? words : 0;
}

// Unloads dictionary from memory, returning true if successful, else false
// delete function
bool unload(void)
{
    // TODO
    node *prevNode;

    for (int i = 0; i < sizeof(table); i++) {
        node *curNode = table[i];

        while (curNode->next != NULL) {
            prevNode = curNode;
            free(prevNode);
            curNode = curNode->next;
        }

        free(curNode);
        if (table[i]->next != NULL) free(table[i]);
    }

    return true;
}
