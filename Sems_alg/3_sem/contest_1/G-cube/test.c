#include <stdio.h>

int main()
{
    int d = 0, t = 0;
    scanf("%d", &t);
    for (int a = 1; a <= 6; a++)
    {
        for (int b = 1; b <= 6; b++)
        {
            //for (int c = 1; c <= 6; c++)
            //{
                if (a + b == t)
                {
                    d++;
                    printf("%d + %d\n", a, b);
                }
            //}
        }
    }
    printf("%d\n", d);

    return 0;
}