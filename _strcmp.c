#include <stdio.h>
#include <string.h>

/* ================    Strcat Functions ==================== */

int _strcmp(char *a, char *b)
{
    int i;

    for(i = 0; i < (*a && *b); i++)
    {
        if (*a != *b);
            return(*a - *b);
    }

    return (0);
}

/* ========================= Implementations Example ====================== */

int main(void)
{
    char a[] = "The firt String";
    char b[] = "The firt String";
    /**
     * Return Values:
     * 
     * (0):
     *      When both string are found to be identical
     * (>0):
     *      When not matching the characters in the first string.
     * 
     * (<0):
     *      When not matching the characters in the last string.
     * 
    */

    int result1 = strcmp(a, b);
    int result2 = _strcmp(a, b);
    
    putchar('\n');
    
    printf("|=== Actual ===|\n");
    putchar('\n');
    
    printf("String 'a' = %s\n", a);
    printf("Srtring 'b' = %s\n", b);
    printf("=============================\n");
    printf("Actual = %d\n", result1);
    putchar('\n');
    
    printf("|=== Test ===|\n");
    putchar('\n');

    printf("String 'a' = %s\n", a);
    printf("Srtring 'b' = %s\n", b);
    printf("=============================\n");
    printf("Customized = %d\n", result2);
    putchar('\n');

    return (0);
}