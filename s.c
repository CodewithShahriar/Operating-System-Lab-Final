/// 1. system() diye compile + run

#include <stdio.h>
#include <stdlib.h>
int main()
{
    system("gcc file.c -o file"); // compile
    system("./file");             // run
    return 0;
}


////2. exec() diye compile + run
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid = fork();

    if (pid == 0)
    {
        execlp("gcc", "gcc", "file.c", "-o", "file", NULL);
    }
    else
    {
        wait(NULL);

        int pid2 = fork();

        if (pid2 == 0)
        {
            execl("./file", "./file", NULL);
        }
        else
        {
            wait(NULL);
        }
    }

    return 0;
}
