#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int grey = 0;
    for(int i = 0; i < (1<<n); i++)
    {
        grey = (i ^ (i / 2));
        for(int j = 0; j < n; j++)
        {
            if(grey & (1<<j))
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");
    }
    return 0;
}