#include "main.h"

int execute(char **argv)
{
    int i;
    pid_t pid;

    if (pid == 0)
    {
        int exe = execve(argv[0], argv, environ);

        if (exe == -1)
            perror("Error");
            return (-1);
  
    }
    else
    {
            waitpid(&i);
            if(WIFEXITED(i))
                i = WEXITSTATUS(i);
    }

    return (i);
}