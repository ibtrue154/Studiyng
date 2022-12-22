#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector< vector<int> > g;
vector<int> dist;
vector<bool> used;
vector<int> p;

void print(vector<int> v, int n)
{
    cout << v.size() - 1 << endl;
    for (int i = 1; i < v.size(); i++)
    {
        int res_r = v[i] / n, res_c = v[i] % n;
        cout << (char)(res_r + (int)'A') << res_c + 1 << endl;
    }
    cout << endl;
}

vector<int> bfs(int s, int t, int n) 
{
    vector<int> dist(n, n);
    vector<int> p(n, -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) 
    {
        int v = q.front();
        q.pop();
        for (int u : g[v]) 
        {
            if (dist[u] > dist[v] + 1) 
            {
                p[u] = v;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    vector<int> path;
    while (t != -1) {
        path.push_back(t);
        t = p[t];
    }
    
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int n = 0, s = 0, d = 0;
    string start, dest;
    cin >> n >> start >> dest;
    int*  adjac = new int[8];
    g.resize(n * n);
    dist.resize(n * n);
    used.resize(n * n, false);
    p.resize(n * n);
    if (start.size() == 2)
    {
        s = ((int)start[0] - (int)'A') * n + ((int)start[1] - (int)'0') - 1;
    }
    if (start.size() == 3)
    {
        s = ((int)start[0] - (int)'A') * n + ((int)start[1] - (int)'0') * 10 + ((int)start[2] - (int)'0') - 1;
    }
    if (dest.size() == 2)
    {
        d = ((int)dest[0] - (int)'A') * n + ((int)dest[1] - (int)'0') - 1;
    }
    if (dest.size() == 3)
    {
        d = ((int)dest[0] - (int)'A') * n + ((int)dest[1] - (int)'0') * 10 + ((int)dest[2] - (int)'0') - 1;
    }
    
    for (int i = 0; i < n * n; i++)
    {
        int a = i / n, b = i % n;
        adjac[0] = i + 2 * n - 1;
        if (!(a + 2 < n && b - 1 >= 0))
        {
            adjac[0] = -1;
        }
        adjac[1] = i + 2 * n + 1;
        if (!(a + 2 < n && b + 1 < n))
        {
            adjac[1] = -1;
        }
        adjac[2] = i + n + 2;
        if (!(a + 1 < n && b + 2 < n))
        {
            adjac[2] = -1;
        }
        adjac[3] = i - n + 2;
        if (!(a - 1 >= 0 && b + 2 < n))
        {
            adjac[3] = -1;
        }
        adjac[4] = i - 2 * n + 1;
        if (!(a - 2 >= 0 && b + 1 < n))
        {
            adjac[4] = -1;
        }
        adjac[5] = i - 2 * n - 1;
        if (!(a - 2 >= 0 && b - 1 >= 0))
        {
            adjac[5] = -1;
        }
        adjac[6] = i - n - 2;
        if (!(a - 1 >= 0 && b - 2 >= 0))
        {
            adjac[6] = -1;
        }
        adjac[7] = i + n - 2;
        if (!(a + 1 < n && b - 2 >= 0))
        {
            adjac[7] = -1;
        }
        for (int j = 0; j < 8; j++)
        {
            //cout << adjac[j] << " ";
            if (adjac[j] >= 0)
                g[i].push_back(adjac[j]);
        }

        //cout << endl;
    }

    vector<int> path = bfs(s, d, n * n);
    print(path, n);
    return 0;
}