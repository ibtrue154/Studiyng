#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char* argv[]) 
{
    int pipefd1[2];
    int pipefd2[2];
    pipe(pipefd1);
    pipe(pipefd2);
    pid_t pid = fork();
    if (pid == 0) 
    {
        dup2(pipefd2[1], 1);
        close(pipefd2[0]);
        close(pipefd2[1]);
        execlp(argv[1], argv[1], NULL);
    }
    close(pipefd1[0]);
    close(pipefd1[1]);
    waitpid(pid, 0, 0);
    pipefd1[0] = pipefd2[0];
    pipefd1[1] = pipefd2[1];
    pipe(pipefd2);
    for (int i = 2; i < argc; ++i) 
    {
        pid = fork();
        if (pid == 0) 
        {
            dup2(pipefd1[0], 0);
            close(pipefd1[0]);
            close(pipefd1[1]);
            if (i < argc - 1) 
            {
                dup2(pipefd2[1], 1);
                close(pipefd2[0]);
                close(pipefd2[1]);
            }
            execlp(argv[i], argv[i], NULL);
        }
        close(pipefd1[0]);
        close(pipefd1[1]);
        waitpid(pid, 0, 0);
        if (i == argc - 1)
            break;
        pipefd1[0] = pipefd2[0];
        pipefd1[1] = pipefd2[1];
        pipe(pipefd2);
    }
    return 0;
}