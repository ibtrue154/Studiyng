#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    char temp[4096];
    int c = 0;
    while(1)
    {
        pid_t p = fork();
        if (p == 0)
            exit((scanf("%s", temp) != EOF));

        else
        {
            int stat;
            waitpid(p, &stat, 0);
            c += WEXITSTATUS(stat);
        }
    } 
    printf("%d\n", c);
    return 0;
}