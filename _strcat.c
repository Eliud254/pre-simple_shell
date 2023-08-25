#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ================    Strcat Functions ==================== */
char *_strcat(char *dest, const char *src)
{
    int m = 0;
    int n = 0;

Here:   
    if (dest[m] != '\0')
    {
        m += 1;
        goto Here;
    }

    while (src[n] != '\0')
    {
        n += 1;
        dest[m] = src[n];
        m++;
    }

    dest[m] = '\0';

    return (dest);   
}


/* ========================= Implementations Example ====================== */

int main()
{
    char src[] = "Source File";
    char dest[100];

    char *result1 = strcat(dest, src);
    char *result2 = _strcat(dest,src);
    
    putchar('\n');
    
    printf("|=== Actual ===|\n");
    putchar('\n');
    
    printf("Src = %s\n", src);
    printf("=============================\n");
    printf("Actual = %s\n", result1);
    putchar('\n');
    
    printf("|=== Test ===|\n");
    putchar('\n');

    printf("Src = %s\n", src);
    printf("=============================\n");
    printf("Customized = %s\n", result2);
    putchar('\n');

    return (0);
}