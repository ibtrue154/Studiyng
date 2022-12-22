#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector< vector<int> > g;
vector<int> used, enter, ret;
set<int> junctions;
int t = 0, n = 0, m = 0;

//p - parent
void dfs(int v, int p = -1) 
{
    used[v] = 1;
    enter[v] = ret[v] = t++;
    int c = 0;//child
    for (int i = 0; i < g[v].size(); i++) 
    {
        int to = g[v][i];
        if (to == p) continue;
        if (used[to]) 
        {
            ret[v] = min(ret[v], enter[to]);
        }
        else 
        {
            dfs(to, v);
            c++;
            ret[v] = min(ret[v], ret[to]);
            if ((ret[to] >= enter[v]) && (p != -1)) junctions.insert(v);
        }
    }
    if ((p == -1) && (c > 1)) 
        junctions.insert(v);
}

int main() 
{
    cin >> n >> m;

    g.resize(n + 1);
    used.resize(n + 1);
    enter.resize(n + 1);
    ret.resize(n + 1);

    for (int i = 1; i <= m; i++) 
    {
        int v1 = 0, v2 = 0;
        cin >> v1 >> v2;

        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    t = 1;
    for (int i = 1; i <= n; i++) 
    {
        if (!used[i]) 
            dfs(i);
    }

    cout << junctions.size() << endl;

    for (int i : junctions) 
        cout << i << ' ';

    return 0;
}