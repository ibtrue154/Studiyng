#include <stdio.h>
#include <stdlib.h>

int isFull(int tlx, int tly, int brx, int bry, int** mat, int** pre)
{
    int area = (brx - tlx + 1) * (bry - tly + 1);
    int sum = pre[brx][bry] - pre[brx][tly - 1] - pre[tlx - 1][bry] + pre[tlx - 1][tly - 1];
    if (sum == area)
    {
        return 1;
    }
    return -1;
}

int main()
{
    int N = 0, max = 0, res = 0;

    scanf("%d", &N);

    int** mat = calloc(N + 1, sizeof(int*));
    int** pre = calloc(N + 1, sizeof(int*));
    for (int i = 0; i < N + 1; i++)
    {
        mat[i] = calloc(N + 1, sizeof(int));
        pre[i] = calloc(N + 1, sizeof(int));
    }

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 1; i < N; i++)
    {
        pre[0][i] = mat[0][i] + pre[0][i - 1];
    }

    for (int i = 1; i < N; i++)
    {
        pre[i][0] = mat[i][0] + pre[i - 1][0];
    }

    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            pre[i][j] = mat[i][j] + pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
        }
    }

   for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            for(int k = 1; k < N + 1; k++)
            {
                if ((i + k > N + 1) || (j + k > N + 1))
                {
                    break;
                }
                res = isFull(i, j, i + k - 1, j + k - 1, mat, pre);
                if (res > 0)
                {
                    if (k > max)
                        max = k;
                }
            }
        }
    }

    printf("%d\n", max);

    return 0;
}