#include <iostream>
#include <vector>

using namespace std;

#define BIG 1000000

int n = 0, m = 0, s = 0;

struct edge{

    int st, de, dist;
    edge(int a, int b, int c) : st(a), de(b), dist(c) {}
};

vector<edge> e;
vector< vector<int> > g;
vector<bool> used;
vector<int> dist;

int sum()
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += dist[i];
    }

    return sum;
}

void dfs(int v)
{
    used[v] = 1;
    for (int i = 0; i < g[v].size(); ++i) 
    {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
    return;
}

bool solve()
{
    dist[s] = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < e.size(); j++) 
        {
            int start = e[j].st;
            int dest = e[j].de;
            int distance = e[j].dist;
            if ((dist[start] < BIG) && (dist[dest] > dist[start] + distance)) 
            {
                dist[dest] = max(-BIG, dist[start] + distance);
            }
        }
    }

    for (int i = 0; i < e.size(); i++) 
    {
        int start = e[i].st;
        int dest = e[i].de;
        int distance = e[i].dist;
        if (dist[start] != BIG && dist[start] + distance < dist[dest])
            return true;
        if ((dist[start] < BIG) && (dist[dest] > dist[start] + distance) && (used[dest] == false)) 
        {
            dfs(dest);
        }
    }

    return false;
}

int main()
{
    cin >> n >> m >> s;

    dist.assign(n, BIG);
    g.resize(n);
    used.resize(n);

    for (int i = 0; i < m; i++) 
    {
        int s = 0, d = 0, dd = 0;
        cin >> s >> d >> dd;
        g[s].push_back(d);
        e.push_back(edge(s, d, dd));
    }
    used.assign(n, false);
    bool neg_cyc = solve();

    if (neg_cyc)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) 
    {
        if (dist[i] == BIG) 
            cout << "UNREACHABLE ";
        else 
            cout << dist[i] << " ";
    }

    cout << endl;

    return 0;
}