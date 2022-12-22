#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>

volatile uint32_t N;
volatile pid_t pid;

void handler (int signum, siginfo_t* info, void *t) 
{
    N = info->si_value.sival_int;
    pid = info->si_pid;
}


int main() 
{
    sigset_t set;
    sigemptyset(&set);
    sigfillset(&set);
    sigdelset(&set, SIGRTMIN);
    sigprocmask(SIG_BLOCK, &set, NULL);

    struct sigaction action;
    action.sa_sigaction = handler;
    action.sa_flags = SA_RESTART | SA_SIGINFO;
    sigaction(SIGRTMIN, &action, NULL);

    while(1) 
    {
        pause();
        if (!N)
            return 0;
        union sigval value;
        memset(&value, 0, sizeof(value));
        value.sival_int = --N;
        sigqueue(pid, SIGRTMIN, value);
    }
    return 0;
}