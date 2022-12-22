#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 0, sum = 0;

    scanf("%d", &count);

    int* mas = (int*)malloc(count * sizeof(int));

    for (int i = 0; i < count; i++)
    {
        scanf("%d", &mas[i]);
    }
    if (mas[0] != 1)
    {
        printf("1");
        return 0;
    }
    sum += mas[0];
    for(int i = 1; i < count; i++)
    {
        if (sum + 1 < mas[i])
        {
            printf("%d", sum + 1);
            return 0;
        }
        sum += mas[i];
    }
    printf("%d", sum + 1);
    return 0;
}