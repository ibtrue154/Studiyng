#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int k = 0, n = 0, p = 0, MaxN = 300, i = 0, j = 0, r = 0, m = 0;
    long min = 0, s = 0;
    int *x = calloc(MaxN + 1, sizeof(int));
    long *d = calloc(MaxN + 1, sizeof(long)), *t = calloc(MaxN + 1, sizeof(long));
    int **pr = calloc(MaxN + 1, sizeof(int*));
    for (int i = 0; i < MaxN + 1; i++)
    {
        pr[i] = calloc(31, sizeof(int));
    }

    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x[i]);
    }

    for (int i = 1; i <= n; i++)
    {
        s = 0;
        for (int j = 1; j <= i - 1; j++)
        {
            s += ((long)x[i] - (long)x[j]);
        }
        d[i] = s;
    }

    for (int k = 2; k <= p; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            t[i] = 1000000000;
            r = i;
            s = 0;

            for (int j = i - 1; j >= 1; j--)
            {
                while ((r > j) && (x[i] - x[r - 1] < x[r - 1] - x[j]))
                {
                    r--;
                    s = s - ((long)x[r] - (long)x[j + 1]) + ((long)x[i] - (long)x[r]);
                }

                s += ((long)(r - j - 1) * ((long)x[j + 1] - (long)x[j]));

                if (s + d[j] < t[i])
                {
                    t[i] = s + d[j];
                    pr[i][k] = j;
                }
            }
        }
        for ( int i = 1; i <= n; i++) // eq to d := t
        {
            d[i] = t[i];
        }
    }

    min = LONG_MAX;

    for (int i = 1; i <= n; i++)
    {
        s = d[i];
        for (int j = i + 1; j <= n; j++)
        {
            s += ((long)x[j] - (long)x[i]);
        }
        if (s < min)
        {
            min = s;
            m = i;
        }
    }

    printf("%ld\n", min);

    k = p;
    while (k > 0)
    {
        d[k] = m;
        m = pr[m][k];
        k--;
    }

    for (int i = 1; i <= p; i++)
    {
        printf("%d ", x[d[i]]);
    }

    printf("\n");

    return 0;
}