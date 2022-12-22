#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    pid_t pid = fork();
    if (pid == 0)
    {
        int n = argc - 1;
        for (int i = 1; i < n; i++) 
        {
            int pipefd[2];
            pipe(pipefd);
            pid = fork();
            if (pid > 0 || pid < 0) 
            {
                waitpid(pid, NULL, 0);
                close(pipefd[1]);
                dup2(pipefd[0], 0);
                close(pipefd[0]);
            } 
            else 
            {
                close(pipefd[0]);
                dup2(pipefd[1], 1);
                close(pipefd[1]);
                execlp(argv[i], argv[i], NULL);
            }
        }
        execlp(argv[n], argv[n], NULL);
    } 
    else
    {
        waitpid(pid, NULL, 0);
    }
    return 0;
}