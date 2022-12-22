#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int min_mul(int* size, int n)
{
    int count = n - 1;
    int** dp = calloc(count, sizeof(int*));
    for (int i = 0; i < count; i++)
    {
        dp[i] = calloc(count, sizeof(int));
    }

    for (int l = 1; l < count; ++l) 
    {
		for (int i = 0; i < count - l; ++i) 
        {
			int j = i + l;
			dp[i][j] = 2147483647;
			for (int k = i; k < j; ++k) 
            {
				dp[i][j] = fmin(dp[i][j], dp[i][k] + dp[k + 1][j] + size[i] * size[k + 1] * size[j + 1]);
			}
		}
	}

	return dp[0][count - 1]; 
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int* size = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &size[i]);
    }

    int res = min_mul(size, n);

    printf("%d\n", res);

    return 0;
}