#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0, y = 0;
    scanf ("%d %d", &x, &y);

    if (x == y)
    {
        printf("F\n");
        return 0;
    }

    int** m = calloc(x, sizeof(int*));
    for (int i = 0; i < x; i++) 
        m[i] = calloc(y, sizeof(int));

    for (int i = 0; i < x; i++)
        m[i][0] = 1;
    for (int i = 0; i < y; i++)
        m[0][i] = 1;
    
    if (x < y)
    {
        for (int i = 0; i < x; i++)
            m[i][i] = 1;
    }
    else
    {
        for (int i = 0; i < y; i++)
            m[i][i] = 1;
    }

    for (int i = 1; i < x; i++)
    {
        for (int j = 1; j < y; j++)
        {
            if ((i != j) && (m[i][j] == 0))
            {
                int d = 0;
                for (int a = i; a >= 0; a--)
                {
                    if (m[a][j] == 2)
                    {
                        d++;
                    }
                }
                for (int b = j; b >= 0; b--)
                {
                    if (m[i][b] == 2)
                    {
                        d++;
                    }
                }
                for (int c = 1; (i - c >= 0) && (j - c >= 0); c++)
                {
                    if (m[i - c][j - c] == 2)
                    {
                        d++;
                    }
                }

                if (d >= 1)
                    m[i][j] = 1;
                else
                    m[i][j] = 2;
            }
        }
    }

    if (m[x - 1][y - 1] == 1)
    {
        free(m);
        printf("F\n");
        return 0;
    }

    else
    {
        free(m);
        printf("S\n");
        return 0;
    }
}