#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/limits.h>
#include <sys/stat.h>

int main()
{
    long long int size_summ = 0;
    char *str_buffer = malloc(sizeof(char) * PATH_MAX);

    struct stat f_stat;
    while (fgets(str_buffer, PATH_MAX, stdin) != NULL)
    {
    	str_buffer[strlen(str_buffer) - 1] = '\0';

    	if (lstat(str_buffer, &f_stat) == 0) 
        {
    		if(S_ISREG(f_stat.st_mode)) 
            {
    			size_summ += f_stat.st_size;
    		}
    	}
    }

    free(str_buffer);

    printf("%lld\n", size_summ);
    return 0;
}