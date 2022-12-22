#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
    int n = atoi(argv[1]);
    for (int i = 1; i <= n; i++)
    {
        if (fork() == 0)
        {
            if (i == n)
                printf("%d\n", i);
			else 
                printf("%d ", i);
			exit(0);
        }
        wait(NULL);
    }
    return 0;
}