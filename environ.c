#include "main.h"

char *_getenv(char *_env)
{
    int checker, i, j;

Here:
    if (environ[i])
    {
        checker = 1;

Again:
        if (environ[i][j] != '=')
        {
            if(environ[i][j] != _env[j])
                checker = 0;
            j++;
            goto Again;
        }

        while (checker == 1)
            break;

        goto Here;
    }

    return (&environ[i][j + 1]);
}

void _env(void)
{
    int i = 0;

Here:
    if (environ[i])
        printf("%s\n", environ[i]);
        i++;
        goto Here;
}