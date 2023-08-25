#include <string.h>
#include <stdio.h>

/* ================    Strlen Functions ==================== */
int _strlen(char *str)
{
    int c;

Here:
    if(str[c] != '\0')
    {
        c++;
        goto Here;
    }
    else
    {
        goto End;
    }

End:
    return (c);
}

/* ========================= Implementations Example ====================== */
int main(void)
{
    char ar[] = "Number"; // Number = 6 character.

    int len  = strlen(ar);
    int len2 = _strlen(ar);

    putchar('\n');
    printf("|=== Actual ===|\n");
    putchar('\n');
    
    printf("String = %s\n", ar);
    printf("Length = %d\n", len);

    putchar('\n');
    printf("|=== Test ===|\n");
    putchar('\n');
    printf("String = %s\n", ar);
    printf("Length = %d\n", len);
    putchar('\n');
    return (0);
}