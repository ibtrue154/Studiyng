#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
volatile int  counter = 0;
volatile int must_exit = 0;

void handler(int signum) 
{
    if (signum == SIGINT)
        ++counter;
    else if (signum == SIGTERM)
        must_exit = 1;
}

int main() 
{
    struct sigaction action;
    action.sa_handler = handler;
    action.sa_flags = SA_RESTART;
    
    sigaction(SIGINT, &action, NULL);
    
    sigaction(SIGTERM, &action, NULL);

    printf("%d\n", getpid());
    fflush(stdout);
    while (must_exit == 0) 
    {
        pause();
    }
    printf("%d\n", counter);
    return 0;
}