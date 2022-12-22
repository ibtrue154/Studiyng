#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    char in[2048];
    memset(in, 0, 2048);

    fgets(in, 2047, stdin);

    for (int i = 0; i < 2047; i++)
    {
        if (in[i] == '\n')
        {
            in[i] = '\0';
        }
    }

    FILE* f = fopen("main.c", "w");
    fprintf(f, "#include <stdio.h>\nint main()\n{\n    printf(\"%%d\\n\", (%s));\n    return 0;\n}\n", in);
    fclose(f);
    pid_t pid = fork();
    if (pid != 0) 
    {
        int stat = 0;
        waitpid(pid, &stat, 0);

        execlp("./a.out", "./a.out", NULL);
    } 
    else 
    {
        execlp("gcc", "gcc", "main.c", NULL);
    }
    return 0;
}