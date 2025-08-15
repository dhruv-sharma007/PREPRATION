#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define Max_Key 256
#define Table_Size 16

/**
 * The Goal of implementing this hashTable is to understand how hash table works internally
 */

typedef struct {
    char key[Max_Key];
    int value;
} Bucket;

Bucket *hash_table[Table_Size];

int hash(char *key) {
    int length = strnlen(key, Max_Key);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += key[i];
        hash_value = (hash_value * key[i]) % Table_Size;
    }
    return hash_value;
}

void init_hash_table() {
    for (int i = 0; i < Table_Size; i++)
        hash_table[i] = NULL;
}

bool add(char *key, int value) {
    int idx = hash(key);
    if (hash_table[idx] != NULL)
        return false;

    Bucket *bucket = malloc(sizeof(Bucket));
    strncpy(bucket->key, key, Max_Key);
    bucket->value = value;
    hash_table[idx] = bucket;
    return true;
}

int get(char *key){
    int idx = hash(key);
    if (hash_table[idx] == NULL)
        return NULL;
    return hash_table[idx];
}

bool remove_key(char *key) {
    int idx = hash(key);
    if (hash_table[idx] == NULL)
        return false;
    free(hash_table[idx]);
    hash_table[idx] = NULL;
    return true;
}

int main() {
    init_hash_table();
    
    add("ONe", 23413);
    add("Two", 23413);
    add("three", 23413);

    return 0;
}

// main issue in this code is collision handling
// i am working on that