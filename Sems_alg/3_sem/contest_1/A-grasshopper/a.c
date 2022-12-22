#include <stdio.h>
#include <stdlib.h>

int max (int a, int b)
{
    if (a < b) return b;
    return a;
}

int main()
{
    int n = 0, m = 0, start = 0;
    scanf("%d %d", &n, &m);
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0] = 1;

    for(int i = 0; i <= n; i++)
    {
        start = max(0, i - m);
        dp[i] = 0;
        for (int j = start; j < i; j++)
        {
            dp[i] += dp[j];
        }
    }

    printf("%d\n", dp[n]);

    return 0;
}