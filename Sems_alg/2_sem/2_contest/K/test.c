#include <stdio.h>
#include <stdlib.h>

int* del(int* arr, int num, int a)
{
    int* mas = (int*)malloc((a - 1) * sizeof(int));
    for(int i = 0; i < num; i++)
    {
        mas[i] = arr[i];
    }
    for(int i = num; i < a - 1; i++)
    {
        mas[i] = arr[i + 1];
    }

    return mas;
}

int find(int* arr, int num, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int a = 0;
    scanf("%d", &a);
    int* m = NULL;

    for (int i = 0; i < a; i++)
    {
        m = (int*)realloc(m, sizeof(int) * (i + 1));
        m[i] = i;
    }
    free(m);
    m = del(m ,find(m, 7, a) , a);
    
    printf("\n");
    for (int i = 0; i < a; i++)
    {
        printf("%d ", m[i]);
    }
    return 0;
}