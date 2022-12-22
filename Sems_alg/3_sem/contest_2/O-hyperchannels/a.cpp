#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector < vector <int> > g;
vector <int> res;
vector < vector<bool> > used;

void euler(int u)
{
    for (int i = 0; i < g[u].size(); i++)
    {
        if (!used[u][i])
        {
            used[u][i] = true;
            euler(g[u][i]);
        }
    }
    res.push_back(u);
    return;
}

int main()
{
    int n = 0, m = 0, x = 0, num = 0;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            if (x == 0 && i != j)
                g[i].push_back(j);
        }
    }
    used.resize(n, vector<bool> (n, false));
    euler(m - 1);
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size() - 1; i++)
    {
        cout << res[i] + 1 << ' ' << res[i + 1] + 1 << endl;
    }
    return 0;
}