#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void print(long long int **mat, int n, int m)
{
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            printf("%lld ", mat[i][j]);   
        }
        printf("\n");
    }
}

long long int isFull(int tlx, int tly, int brx, int bry, long long int** mat, long long int** pre)
{
    int sum = pre[brx][bry] - pre[brx][tly - 1] - pre[tlx - 1][bry] + pre[tlx - 1][tly - 1];
    return sum;
}

int main()
{
    int N = 0, M = 0;
    long long int res = 0, max = LLONG_MIN;

    scanf("%d %d", &N, &M);

    long long int** mat = calloc(N + 1, sizeof(long long int*));
    long long int** pre = calloc(N + 1, sizeof(long long int*));
    for (int i = 0; i < N + 1; i++)
    {
        mat[i] = calloc(M + 1, sizeof(long long int));
        pre[i] = calloc(M + 1, sizeof(long long int));
    }

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < M + 1; j++)
        {
            scanf("%lld", &mat[i][j]);
        }
    }

    for (int i = 1; i < M; i++)
    {
        pre[0][i] = mat[0][i] + pre[0][i - 1];
    }

    for (int i = 1; i < N; i++)
    {
        pre[i][0] = mat[i][0] + pre[i - 1][0];
    }

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < M + 1; j++)
        {
            pre[i][j] = mat[i][j] + pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
        }
    }

    print(pre, N, M);

   for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < M + 1; j++)
        {
            for(int k = 0; k < N + 1; k++)
            {
                for (int t = 0; t < M + 1; t++)
                {
                    if ((i + k > N + 1) || (j + t > M + 1))
                    {
                        break;
                    }
                    res = isFull(i, j, i + k - 1, j + t - 1, mat, pre);
                    if (res > max)
                    {
                        max = res;
                    }
                }
            }
        }
    }

    printf("%lld\n", max);

    return 0;
}