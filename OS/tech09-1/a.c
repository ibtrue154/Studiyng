#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
volatile int  counter = 0;
volatile int must_exit = 0;

void handler(int signum) 
{
    if (signum == SIGUSR1) 
    {
        ++counter;
    } 
    else if (signum == SIGUSR2) 
    {
        counter *= -1;
    }
    else if (signum == SIGTERM) 
    {
        must_exit = 1;;
    }
}

int main() {

    struct sigaction action;
    action.sa_handler = handler;
    action.sa_flags = SA_RESTART;

    sigaction(SIGUSR1, &action, NULL);
    
    sigaction(SIGUSR2, &action, NULL);

    sigaction(SIGTERM, &action, NULL);

    printf("%d\n", getpid());
    fflush(stdout);
    scanf("%d", &counter);
    while (!must_exit) 
    {
        pause();
        printf("%d ", counter);
        fflush(stdout);
    }

    return 0;
}