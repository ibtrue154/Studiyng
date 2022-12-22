#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void * x1, const void * x2)
{
  return ( *(int*)x1 - *(int*)x2 );
}

int min(int x1, int x2)
{
    if (x1 < x2) return x1;
    return x2;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int* x = (int*) calloc(n, sizeof(int));
    int* s = (int*) calloc(n - 1, sizeof(int));
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
    
    qsort(x, n, sizeof(int), compare);

    if(n == 2)
    {
       printf("%d", x[1] - x[0]);
       return 0;
    }

    s[0] = x[1] - x[0];
    s[1] = x[2] - x[0];

    for(int i = 2; i < n - 1; ++i)
    {
        s[i] = min(s[i - 1], s[i - 2]) + abs(x[i] - x[i + 1]);
    }
    
    printf("%d\n", s[n - 2]);

    return 0;
}