#include "main.h"

void *memory(unsigned int a, unsigned int b)
{
    char *k = NULL;
    unsigned int i = 0;

    unsigned int t = (a * b);

    if (a && b)
    {
        if(a == 0 || b == 0)
        {
            return (NULL);
        }

        k = malloc(t);
        
        if (k == NULL)
        {   
            perror("Error");
            exit(1);
        }
        
        for(i = 0; i < t; i++)
        {
            k[i] = 0;
        }
    }

    return (k);
}