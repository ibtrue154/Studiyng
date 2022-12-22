#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char in[2048], terminal[2048];
    memset(in, 0, 2048);
    memset(terminal, 0, 2048);
    fgets(in, 2047, stdin);
    for (int i = 0; i < 2048; i++)
    {
        if (in[i] == '\n')
            in[i] = '\0';
    }
    sprintf(terminal, "print(%s)", in);
    execlp("python3", "python3", "-c", terminal, NULL);

    return 0;
}