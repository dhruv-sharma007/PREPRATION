#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "HashTable.h"

Bucket *hash_table[Table_Size];

int hash(char *key)
{
    int length = strnlen(key, Max_Key);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++)
    {
        hash_value += key[i];
        hash_value = (hash_value * key[i]) % Table_Size;
    }
    return hash_value;
}

void init_hash_table()
{
    for (int i = 0; i < Table_Size; i++)
        hash_table[i] = NULL;
}

bool add(char *key, int value)
{
    int idx = hash(key);

    Bucket *bucket = malloc(sizeof(Bucket));
    strncpy(bucket->key, key, Max_Key);
    bucket->next = NULL;
    bucket->value = value;

    if (hash_table[idx] != NULL)
    {
        Bucket *current = hash_table[idx];
        while (current->next != NULL)
        {
            current = current->next;
        }
        hash_table[idx] = bucket;
        return false;
    }

    hash_table[idx] = bucket;
    return true;
}

int get(char *key)
{
    int idx = hash(key);
    if (hash_table[idx] == NULL)
    {
        return NULL;
    }
    Bucket *current = hash_table[idx];
    while (strncmp(current->key, key, Max_Key) != 0)
    {
        current = current->next;
    }
    return current->value;
}

// Address Boundry Error
bool removeByKey(char *key)
{
    int idx = hash(key);
    if (hash_table[idx] == NULL)
        return false;

    Bucket *current = hash_table[idx];
    Bucket *prev = NULL;
    while (strncmp(current->key, key, Max_Key) != 0)
    {
        prev = current;
        current = current->next;
    }
    if (current->next != NULL){
        prev->next = current->next;
    }
    free(current);
    hash_table[idx] = NULL;
    return true;
}
