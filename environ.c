#include "main.h"

char *_getenv(char *env_var)
{
    int checker;
    int i = 0;
    int j = 0;


    while (environ[i])
    {
        checker = 1;

Again:
        if (environ[i][j] != '=')
        {
            if(environ[i][j] != env_var[j])
                checker = 0;
            j++;
            goto Again;
        }

        if (checker == 1)
            break;

        i++;
    }

    return (&environ[i][j + 1]);
}

void _env(void)
{
    int i = 0;

Here:
    if (environ[i])
    {
        printf("%s\n", environ[i]);
        i++;
        goto Here;
    }
}