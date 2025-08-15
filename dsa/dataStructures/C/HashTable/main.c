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
