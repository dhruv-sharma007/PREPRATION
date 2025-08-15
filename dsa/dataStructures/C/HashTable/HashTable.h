#ifndef HASHTABLE_H
#define HASHTABLE_H

#include<stdbool.h>
#define Max_Key 256
#define Table_Size 16

    typedef struct Bucket
{
    char key[Max_Key];
    int value;
    struct Bucket *next;
} Bucket;

int hash(char *key);
void init_hash_table();
bool add(char *key, int value);
int get(char *key);
bool removeByKey(char *key);

#endif