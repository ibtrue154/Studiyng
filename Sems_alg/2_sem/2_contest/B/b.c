#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pow = 0, count = 0, mod = 0, res = 0, koef = 1, add = 0;

    scanf("%d %d %d", &pow, &count, &mod);

    int* rate = malloc((pow + 1) * sizeof(int));
    int* x = malloc(count * sizeof(int));

    for (int i = 0; i < pow + 1; i++)
    {
        scanf("%d", &rate[i]);
    }

    for (int i = 0; i < count; i++)
    {
        scanf("%d", &x[i]);
    }

    for (int i = 0; i < count; i++)
    {
        res = 0;
        koef = 1;
        for (int j = pow; j >= 0; j--)
        {
            add = (1LL * rate[j] * koef) % mod;
            res =(res + add) % mod;
            koef = (1LL * koef * x[i]) % mod;
        }
        x[i] = res % mod;
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d\n", x[i]);
    }
    free(rate);
    free(x);

    return 0;
}