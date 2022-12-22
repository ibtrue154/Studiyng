#include <string>
#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>

int main()
{
    int N = 0;
    scanf("%d", &N);
    
    int* mas = new int[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &mas[i]);
    }

    int* d = new int[N];
    int* p = new int[N];

    for (int i = 0; i < N; i++) 
    {
        d[i] = 1;
        p[i] = -1;
        for (int j = 0; j < i; j++)
        {
            if (mas[j] < mas[i])
            {
                if (1 + d[j] > d[i])
                {
                    d[i] = 1 + d[j];
                    p[i] = j;
                }
            }
        }
    }

    int ans = d[0], pos = 0;
    for (int i = 0; i < N; i++)
    {
        if (d[i] > ans)
        {
            ans = d[i];
            pos = i;
        }
    }
    std::cout << ans << ' ';

    std::vector<int> path;
    while (pos != -1)
    {
        path.push_back(pos);
        pos = p[pos];
    }
    std::reverse (path.begin(), path.end());
    for (int i = 0; i < path.size(); i++)
    {
        std::cout << path[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}