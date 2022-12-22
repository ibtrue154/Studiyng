//заинклюдить библиотеку сисколов и поменять номера константы на вызовы слова 
//sys_write и sys_exit
long syscall(long number, ...);

void _start()
{
    syscall(1, 1, "Hello, World!\n", 14);
    syscall(60, 0);
}