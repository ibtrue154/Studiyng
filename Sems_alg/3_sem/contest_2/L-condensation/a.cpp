#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector < vector<int> > g, gr;
vector<char> used;
vector<int> order, component;
set < pair<int, int> > nme;
int n = 0, m = 0, cnt = 0;

void dfs1 (int v) 
{
	used[v] = true;
	for (int i = 0; i < g[v].size(); i++)
		if (!used[ g[v][i] ])
			dfs1 (g[v][i]);
	order.push_back (v);
}
 
void dfs2 (int v) 
{
	used[v] = true;
	component[v] = cnt;
	for (int i = 0; i < gr[v].size(); i++)
		if (!used[ gr[v][i] ])
			dfs2 (gr[v][i]);
}

int main()
{
    cin >> n >> m;
    g.resize(n);
    gr.resize(n);
    used.resize(n);
    component.reserve(n);

    for (int i = 0; i < m; i++)
    {
        int b = 0, e = 0;
        cin >> b >> e;
        g[b - 1].push_back(e - 1);
        gr[e - 1].push_back(b - 1);
    }

    used.assign(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
			dfs1 (i);
    }
    used.assign(n, false);
    cnt = 1;
	for (int i = 0; i < n; i++)
    {
		int v = order[n - 1 - i];
		if (!used[v]) 
        {
			dfs2(v);
			cnt++;
		}
	}
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < g[i].size(); j++) 
        {
            if (component[i] != component[g[i][j]])
                nme.insert(make_pair(component[i], component[g[i][j]]));
        }
    }
    cout << nme.size() << endl;
    return 0;
}