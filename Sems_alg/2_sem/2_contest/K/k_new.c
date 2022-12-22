#include <stdio.h>
#include <stdlib.h>

typedef long long int lli;

int find(lli** mas, lli num, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (mas[i][0] == num)
        {
            return i;
        }
    }
    return -1;
}

void ShellSort(int n, long long int* mass)
{
    int i, j, step;
    long long int tmp;
    for (step = n / 2; step > 0; step /= 2)
        for (i = step; i < n; i++)
        {
            tmp = mass[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < mass[j - step])
                    mass[j] = mass[j - step];
                else
                    break;
            }
            mass[j] = tmp;
        }
}

int main()
{
    int size = 0, k = 0, ko = 0;
    lli b = 0;
    lli **res = (lli**)malloc(1 * sizeof(lli*));
    res[0] = (lli*)malloc(2 * sizeof(lli));

    for (lli i = 0; i < 200002; i++)
    {
        scanf("%lld", &b);
        if (b == 0)
        {
            ko++;
            if (ko == 2)
            {
                break;
            }
        }
        else
        {
            if (find(res, b, size) == -1)
            {
                res[k][0] = b;
                res[k][1]++;
                k++;
                size++;
                res = (lli**)realloc(res, (size + 1) * sizeof(lli*));
                res[k] = (lli*)malloc(2 * sizeof(lli));
            }
            else
            {
                res[find(res, b, size)][1]++;
            }
        }
    }
    k = 0;
    lli* ans = (lli*) malloc(1 * sizeof(lli));
    for (int i = 0; i < size; i++)
    {
        if (res[i][1] == 1)
        {
            ans[k] = res[i][0];
            k++;
            ans = (lli*)realloc(ans, (k + 1) * sizeof(lli));
        }
    }
    ShellSort(k, ans);
    for (int i = 0; i < k; i++)
    {
        printf("%lld ", ans[i]);
    }
    return 0;
}