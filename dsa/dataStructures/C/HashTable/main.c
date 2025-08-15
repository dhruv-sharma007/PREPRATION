#include <stdio.h>
#include "HashTable.h"
#include <stdbool.h>
int main()
{
    init_hash_table();
    add("ONe", 1);
    add("Two", 2);
    add("Three", 3);

    printf("ONe %d\n", get("ONe"));
    printf("Two %d\n", get("Two"));
    printf("Three %d\n", get("Three"));
    removeByKey("Three");
    printf("Three %d\n", get("Three"));
    return 0;
}

// Note: HashSet is just a thin wrapper of hashMap so the core idea is same 
// I alread built a core idea of HashMap so there is no need to implement same thing with little changes

// HashTable and HashMap are same but have little different : 
/**
 * hashTable is old outdated class of java it also sotres key-value. Same core idea but it is thread safe and dont allow null keys etc...
 */