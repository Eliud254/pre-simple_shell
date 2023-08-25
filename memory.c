#include "main.h"

void *memory(unsigned int a, unsigned int b)
{
    char *k = NULL;
    unsigned int j = 0;
    char *status = NULL;

    for (; a && b;)
    {
        while (a == 0 || b == 0)
            return (status);
            break;
        
        k = malloc(a * b);
        
        if (k == NULL)
            return (status);
        
        for(; j < (a * b); j++)
            k[j] = 0;
    }

    return (k);
}