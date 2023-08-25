#include "main.h"

int execute(char **argv)
{
    int i, pid;

    pid = fork();

    if (pid == 0)
    {
        int exe = execve(argv[0], argv, environ);

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