#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) 
{
    char *cmd = argv[1];
    char *in_file = argv[2];

    int in = open(in_file, O_RDONLY);
    dup2(in, 0);
    close(in);

    int pipefd[2];
    pipe(pipefd);

    pid_t pid = fork();
    if (pid == 0) 
    {
        dup2(pipefd[1], 1);
        close(pipefd[1]);
        execlp(cmd, cmd, NULL);
    } 
    else 
    {
        close(pipefd[1]);
        unsigned long long total_count = 0;
        int count;
        char buffer[4096];

        while ((count = read(pipefd[0], buffer, sizeof(buffer))) > 0)
            total_count += count;

        waitpid(pid, 0, 0);
        printf("%lld\n", total_count);
    }
}