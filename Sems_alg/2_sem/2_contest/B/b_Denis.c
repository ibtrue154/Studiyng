#include <stdio.h>
#include <stdlib.h>

int add(int a, int b, int mod)
{
    a += b;
    if(a >= mod)
    {
        a -= mod;
    }

    return a;
}

int mull(int a, int b, int mod)
{
    return (1LL * a * b) % mod;
}


int solve(int* koef, int n, int mod, int x)
{
    int ans = 0;
    int pr = 1;
    for(int i = n - 1; i >= 0; i--)
    {
        ans = add(ans, mull(koef[i], pr, mod), mod);
        pr = mull(pr, x, mod);
    }
    return ans;
}

int main()
{
    int n, q, mod;
    scanf("%d%d%d", &n, &q, &mod);
    int* koef = (int*)malloc(sizeof(int) * (n + 1));

    for(int i = 0; i < n + 1; i++)
    {
        scanf("%d", &koef[i]);
    }

    for(int i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", solve(koef, n + 1, mod, x));
    }
    free(koef);
    return 0;
}