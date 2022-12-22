#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count = 0, coins = 0, change = 0;
    scanf ("%d", &count);

    int* mas = malloc(count * sizeof(int));

    for (int i = 0; i < count; i++)
    {
        scanf ("%d", &mas[i]);
    }
    for (int i = 0; i < count; i++)
    {
        if (mas[i] == 5)
        {
            change++;
        }
        else
        {
            mas[i] -= 5;
            if ((mas[i] / 5) >= change)
            {
                coins += ((mas[i] / 5) - change);
                change = 0;
            }
            else
            {
                change -= (mas[i] / 5);
            }
        }
    }
    printf("coins: %d, change: %d", coins, change);
}