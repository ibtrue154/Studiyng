#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int sum(int* mas, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += mas[i];
    }

    return res;
}

int main(int argc, char** argv) 
{
    int pipe_fd[2];
    pipe(pipe_fd);
    pid_t pid = fork();
    if (pid == 0) 
    {
        close(pipe_fd[0]);
        dup2(pipe_fd[1], 2);
        execlp("gcc", "gcc", argv[1], NULL);
    }
    close(pipe_fd[1]);
    dup2(pipe_fd[0], 0);
    waitpid(pid, NULL, 0);
    char buffer[4096];
    int errcnt[4096], wcnt[4096];
    memset(errcnt, 0, sizeof(int) * 4096);
    memset(wcnt, 0, sizeof(int) * 4096);
    
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) 
    {
        int line = 0;
        bool flag = 0;
        for (unsigned i = 0; i < strlen(buffer); ++i) 
        {
            if (buffer[i] >= '0' && buffer[i] <= '9') 
            {
                line = line * 10 + (buffer[i] - '0');
                flag = 1;
            } 
            else if (flag == 1) 
            {
                break;
            }
        }
        if (strstr(buffer, "error:")) 
        {
            errcnt[line] = 1;
        }
        if (strstr(buffer, "warning:")) 
        {
            wcnt[line] = 1;
        }
    }

    int error = sum(errcnt, 4096);
    int warning = sum(wcnt, 4096);

    printf("%d %d\n", error, warning);

    return 0;
}