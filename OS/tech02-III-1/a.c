//заинклюдить библиотеку сисколов и поменять номера константы на вызовы слова 
//sys_write и sys_exit

long syscall(long number, ...);

void _start()
{
    char in[1000];

    int len = 0;

    do
    {
        len = syscall(0, 0, in, 999);
        syscall(1, 1, in, len);
    } while (len != 0);
    
    syscall(60, 0);
}