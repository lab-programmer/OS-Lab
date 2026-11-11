#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig)
{
    if (sig == SIGINT)
        printf("\nSIGINT received\n");

    else if (sig == SIGTERM)
        printf("\nSIGTERM received\n");

    else if (sig == SIGHUP)
        printf("\nSIGHUP received\n");

    else if (sig == SIGALRM)
        printf("\nSIGALRM received\n");

    else if (sig == SIGUSR1)
        printf("\nSIGUSR1 received\n");
}

int main()
{
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    signal(SIGHUP, handler);
    signal(SIGALRM, handler);
    signal(SIGUSR1, handler);

    printf("Signal handlers registered.\n");
    printf("Process ID: %d\n", getpid());

    alarm(10);

    while (1)
    {
        pause();
    }

    return 0;
}