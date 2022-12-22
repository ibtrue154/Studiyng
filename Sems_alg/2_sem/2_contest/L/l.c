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

int main()
{
    int lena = 0, lenb = 0;

    scanf("%d", &lena);
    scanf("%d", &lenb);

    lli* a = (lli*)malloc(lena * sizeof(lli));
    lli* b = (lli*)malloc(lenb * sizeof(lli));
    for (int i = 0; i < lena; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (lli i = 0; i < lenb; i++)
    {
        scanf("%lld", &b[i]);
    }

    int size = 0, k = 0;
    lli **res = (lli**)malloc(1 * sizeof(lli*));
    res[0] = (lli*)malloc(2 * sizeof(lli));

    for (lli i = 0; i < lena; i++)
    {
        if (find(res, a[i], size) == -1)
        {
            res[k][0] = a[i];
            res[k][1]++;
            k++;
            size++;
            res = (lli**)realloc(res, (size + 1) * sizeof(lli*));
            res[k] = (lli*)malloc(2 * sizeof(lli));
        }
        else
        {
            res[find(res, a[i], size)][1]++;
        }
    }

    for (int i = 0; i < lenb; i++)
    {
        if (find(res, b[i], size) == -1)
        {
            res[k][0] = b[i];
            res[k][1]++;
            k++;
            size++;
            res = (lli**)realloc(res, (size + 1) * sizeof(lli*));
            res[k] = (lli*)malloc(2 * sizeof(lli));
        }
        else
        {
            res[find(res, b[i], size)][1]++;
        }
    }
    /*printf("size: %d\n[ ", size);
    for (int i = 0; i < size; i++)
    {
        printf("[%lld, %lld] ", res[i][0], res[i][1]);
    }
    printf("]\n");*/
    for (int i = 0; i < size; i++)
    {
        if (res[i][1] > 1)
        {
            printf("%lld ", res[i][0]);
        }
    }
    return 0;
}