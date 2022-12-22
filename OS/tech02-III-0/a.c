#include <sys/syscall.h>
long syscall(long number, ...);

void _start()
{
    syscall(SYS_write, 1, "Hello, World!\n", 14);
    syscall(SYS_exit);
}