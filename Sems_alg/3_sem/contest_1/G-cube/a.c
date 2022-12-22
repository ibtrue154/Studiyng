#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

int main()
{
    int m = 0, n = 0;
    scanf("%d %d", &n, &m);
    if ((n > m) || (m > n * 6))
    {
        printf("0\n");
        return 0;
    }
    if ((n == m) || (m == n * 6))
    {
        printf("%.10lf", (double) 1 / (pow(6, n)));
        return 0;
    }

    double** a = (double**)malloc((m + 1) * sizeof(double*));
    assert(a != NULL);
    for (int i = 0; i < m + 1; i++)
    {
        a[i] = (double*)malloc((n + 1) * sizeof(double));
        assert(a[i] != NULL);
    }

    for (int i = 1; (i <= 6) && (m - i >= 0); i++)
    {
        a[i][1] = (double)1 / 6;
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = i; j < m + 1; j++)
        {
            for (int t = 1; (t <= 6) && (j - t >= i - 1); t++)
            {
                a[j][i] += (double)(a[j - t][i - 1] / 6);
            }
        }
    }

    printf("%.10lf\n", a[m][n]);

    return 0;
}