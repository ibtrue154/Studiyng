#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector< vector<int> > g, mas;
vector<bool> used;
vector<int> tin, fup;
set<int> ans;
int t = 0, n = 0, m = 0;

int check(int s, int d)
{
    for (int i = 0; i < m; i++)
    {
        if ((mas[i][0] == s && mas[i][1] == d) || (mas[i][0] == d && mas[i][1] == s))
        {
            return i + 1;
        }
    }

    return -1;
}

void IS_BRIDGE(int v, int to)
{
    ans.insert(check(v, to));
    return;
}

void dfs (int v, int p = -1) 
{
	used[v] = true;
	tin[v] = fup[v] = t++;
	for (int i = 0; i < g[v].size(); i++) 
    {
		int to = g[v][i];
		if (to == p)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else 
        {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v])
            {
				IS_BRIDGE(v, to);
            }
		}
	}
}

int main()
{
    cin >> n >> m;
    mas.resize(m);
    g.resize(n + 1);
    tin.resize(n + 1);
    fup.resize(n + 1);
    used.resize(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int v1 = 0, v2 = 0;
        cin >> v1 >> v2;
        mas[i].push_back(v1);
        mas[i].push_back(v2);
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    for (int i = 0; i <= n; i++)
		if (!used[i])
			dfs (i);

    cout << ans.size() << endl;
    for (int i : ans) 
        cout << i << ' ';

    return 0;
}