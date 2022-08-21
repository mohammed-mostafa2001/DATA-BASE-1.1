#include <stdio.h>
#include <stdlib.h>
#include "count.h"
extern int top_counter;
uint8_type SDB_GetUsedSize()
{
    printf("There are %d node(s)\n",top_counter);
    return top_counter;
}
