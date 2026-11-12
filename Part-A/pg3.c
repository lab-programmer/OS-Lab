 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int i, pid;

    for(i = 0; i < 5; i++)
    {
        pid = fork();

        if(pid < 0)
        {
            printf("Fork failed\n");
            return 1;
        }
        else if(pid == 0)
        {
            printf("Child %d: Process ID = %d\n", i+1, getpid());
            exit(0);
        }
    }

    for(i = 0; i < 5; i++)
    {
        wait(NULL);
    }

    printf("Parent process: All children have finished.\n");

    return 0;
}
