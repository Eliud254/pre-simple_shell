#include <string.h>
#include <stdio.h>

/* ================    Strcpy Functions ==================== */

char* _strcpy(char* dest, const char* src)
{
    char* str;

    str = dest;

Here:
    if (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;

        goto Here;
    }

    *dest = '\0';

    return (str);
}

/* ========================= Implementations Example ====================== */
int main()
{
    char src[] = "Source File";
    char dest[100];

    char *result1 = strcpy(dest, src);
    char *result2 = _strcpy(dest,src);
    
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
}