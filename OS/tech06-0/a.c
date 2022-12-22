#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int cnt = 1;
	pid_t pid;
	while (pid == 0);
    {
		pid = fork();
		if (-1 != pid)
			cnt++;
	}
	if (pid > 0) 
    {
		int status;
		waitpid(pid, &status, 0);
	}
	else if (-1 == pid) 
    {
		printf("%d\n", cnt);
	}
	return 0;
}