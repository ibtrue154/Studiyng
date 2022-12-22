#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int flag = 0;
vector< vector<int> > g;
vector<int> used, path;

void dfs(int v)
{
    if (flag == 1)
        return;
    used[v] = 1;
    path.push_back(v);

    for (int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if (used[to] == 1)
        {
            path.push_back(to);
            flag = 1;
            return;
        }
        else
            dfs(to);
        if (flag == 1)
            return;
    }
    used[v] = 2;
    path.pop_back();
}

int main()
{
    int n = 0, m = 0, s = 0, d = 0;
    scanf("%d %d", &n, &m);
    g.resize(n + 1);
    used.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &s, &d);
        g[s].push_back(d);
    }

    for (int i = 1; i <= n; i++)
    {
        if (used[i] == 0)
        {
            dfs(i);
            if (flag == 1)
                break;
        }
    }

    if (flag == 1)
    {
        int to = path.back();
        int i = path.size() - 2;
        while (path[i] != to)
            i--;
        printf("YES\n");
        for(; i < path.size() - 1; i++)
        {
            printf("%d ", path[i]);
        }
        printf("\n");
        return 0;
    }

    else
    {
        printf("NO\n");   
        return 0;
    }

    return 0;
}