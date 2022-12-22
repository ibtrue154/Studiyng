#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int agrc, char** argv)
{
    int N = atoi(argv[1]);
    printf("1");
    for(int i = 2; i <= N; i++)
    {
        if(fork() == 0)
        {
            printf(" %d", i);
            _exit(0);
        }
        else
        {
            wait(0);
        }
    }
    printf("\n");
    return 0;
}