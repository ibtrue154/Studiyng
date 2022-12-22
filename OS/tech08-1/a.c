#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char* CMD1 = argv[1];
    char* CMD2 = argv[2];
    pid_t pid = fork();
    if (pid == 0) 
    {
        int pipefd[2];
        pipe(pipefd);
        pid = fork();
        if (pid == 0) 
        {
            close(pipefd[0]);
            dup2(pipefd[1], 1);
            close(pipefd[1]);
            execlp(CMD1, CMD1, NULL);
        } 
        else 
        {
            waitpid(pid, NULL, 0);
            close(pipefd[1]);
            dup2(pipefd[0], 0);
            close(pipefd[0]);
            execlp(CMD2, CMD2, NULL);
        }
    } 
    else
    {
        waitpid(pid, NULL, 0);
    }
    return 0;
}