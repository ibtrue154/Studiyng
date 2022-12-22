#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > g;
vector<int> comp;
 
void dfs (int v, int num) 
{
	comp[v] = num;
    for (int u : g[v])
        if (!comp[u])
            dfs(u, num);
}
 


int main()
{
    int n = 0, m = 0, v1 = 0, v2 = 0;
    cin >> n >> m;
    g.resize(n + 1);
    comp.resize(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    int num = 0;
    for (int v = 1; v < n + 1; v++)
        if (!comp[v])
            dfs(v, ++num);

    cout << num << endl;

    for (int i = 1; i < comp.size(); i++)
    {
        cout << comp[i] << ' ';
    }
    return 0;
}