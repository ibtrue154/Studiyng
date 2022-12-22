#include <stdio.h>
#include <stdlib.h>

int f(int n, int left)
{
    if ((n > 0) && (left < 0))
    {
        return 0;
    }
    else if (n == 1)
    {
        if ((left >= 0) && (left <= 9))
        {
            return 1;
        }
        return 0;
    }

    int res = 0;

    for (int i = 0; i < 10; i++)
    {
        res += f(n - 1, left - i);
    }

    return res;
}

/*int solve(int n, int left)
{
    int** m = calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        m[i] = calloc((9 * n)/2, sizeof(int));
    }


}*/

int main()
{
    int n = 0;
    scanf ("%d", &n);

    printf ("%d\n", f(n, (9 * n) / 2));
}