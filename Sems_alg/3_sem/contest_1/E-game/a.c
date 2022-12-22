#include <stdio.h>
#include <math.h>

int isqrt(int n) 
{
   int a = sqrt(n);
   int b = 0;
   for (int i = 1; i <= a; i = i+1)
          b = b + 1;
   return b;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int a = 2;

    while (a < n)
    {
        a += isqrt(a + isqrt(a) + 1) + 1;
        if (a == n)
        {
            printf("Second\n");
            break;
        }
        else if (a > n)
        {
            printf("First\n");
            break;
        }
    }

    return 0;
}