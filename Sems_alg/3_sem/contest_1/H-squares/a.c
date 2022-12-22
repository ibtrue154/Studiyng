#include <stdio.h>
#include <math.h>

int main()
{
    int a = 0, c = 0;
    scanf("%d", &a);

    int b = (sqrt(a) / 1);

    b *= b;

    while (a != 0)
    {
        if (a / b == 0)
        {
            b = sqrt(a) / 1;
            b *= b;
        }
        
        else 
        {
            c += a / b;
            a %= b;
        }
    }

    printf("%d\n", c);

    return 0;
}