#include "main.h"

void *memory(unsigned int a, unsigned int b)
{
    char *k = NULL;
    unsigned int j = 0;

    if(a && b)
    {
        if(a == 0 || b == 0)
            return (NULL);
        
        k = malloc(a * b);
        
        if (k == NULL)
            return (NULL);
        
        for(; j < (a * b); j++)
            k[j] = 0;
    }

    return (k);
}