#include "main.h"

int execv(char **args)
{
    int i;
    pid_t pid;

    if (pid == 0)
    {
        int exe = execve(args[0], args, environ);

        if (exe == -1)
            perror("Error");
            return (-1);
  
    }
    else
    {
            wait(&i);

            if(WIFEXITED(i))
                i = WEXITSTATUS(i);
    }

    return (i);
}