#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

#define Bolshoe_chislo  1000000

void floyd_(int** graph, int n)
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j]) 
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
    return;
}

void print(int** g, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }
    return;
}

int main()
{
    int n = 0, ans = -1;
    cin >> n;
    int** g = (int**)calloc(n, sizeof(int**));

    for (int i = 0; i < n; i++)
        g[i] = (int*)calloc(n, sizeof(int*));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> g[i][j];
            if (g[i][j] < 0)
                g[i][j] = Bolshoe_chislo;
        }
    }

    floyd_(g, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((g[i][j] > ans) && (g[i][j] < Bolshoe_chislo))
                ans = g[i][j];
        }
    }
    //print(g, n, n);
    for (int i = 0; i < n; i++)
    {
        free(g[i]);
    }
    free(g);

    cout << ans << endl;

    return 0;
}