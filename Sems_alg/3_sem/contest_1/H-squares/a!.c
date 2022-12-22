#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int f(int a, int b, int c) 
{
    printf("a = %d, b = %d, c = %d\n", a, b, c);

    if (a == 0)
    {
        return c;
    }
    if (a / b == 0)
    {
        b = sqrt(a) / 1;
        b *= b;
        f(a, b, c);
    }
    
    else 
    {
        c += a / b;
        a %= b;
        f(a, b, c);
    }
}

int main()
{
    int a = 0, c = 0;
    scanf("%d", &a);

    int b = (sqrt(a) / 1);

    b *= b;

    c = f(a, b, c);

    printf("%d\n", c);

    return 0;
}