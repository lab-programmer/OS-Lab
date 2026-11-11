
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid;

    for (int i = 1; i <= 5; i++)
    {
        pid = fork();

        if (pid < 0)
        {
            printf("Fork error!\n");
            exit(1);
        }

        if (pid == 0)
        {
            printf("Forked child process %d, running with pid = %d\n",
                   i, getpid());

            sleep(2);
            exit(0);
        }
    }

    printf("Parent process executing, waiting for the children to finish\n");

    // Wait for all 5 child processes
    for (int i = 1; i <= 5; i++)
    {
        wait(NULL);
    }

    printf("All child processes finished, parent continues\n");

    return 0;
}
