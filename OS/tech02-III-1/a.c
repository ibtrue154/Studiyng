#include <sys/syscall.h>
#include <unistd.h>
long syscall(long number, ...);

void _start()
{
    char in[1000];

    int len = 0;

    do
    {
        len = syscall(SYS_read, STDIN_FILENO, in, 999);
        syscall(SYS_write, STDOUT_FILENO, in, len);
    } while (len != 0);
    
    syscall(SYS_exit, 0);
}