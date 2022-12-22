#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

vector< vector<int> > graph;
vector<int> used;
deque<int> l;

/*void graph_print(vector< vector<int> > graph, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "i = " << (char)(i + (int)'A') << ", " << i << "; ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    return;
}*/

int check(vector< vector<int> > graph, int i, int x)
{
    for (int j = 0; j < graph[i].size(); j++)
    {
        if (graph[i][j] == x)
            return 1;
    }
    return 0;
}

void dfs(int v)
{
    used[v] = 1;
    for (int u : graph[v])
    {
        if (used[u] == 0)
        {
            dfs(u);
        }
    }
    used[v] = 2;
    l.push_back(v);
    //cout << 'a' << endl;
    return;
}

void toposort(int n)
{
    for (int i = 0; i < n; i++)
        used[i] = 0;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (used[i] == 0)
        {
            dfs(i);
        }
    }
    return;
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    graph.resize(n);
    used.resize(n);
    string s1, s2;
    cin >> s1;
    for (int i = 0; i < m - 1; i++)
    {
        cin >> s2;
        for (int j = 0; j < n; j++)
        {
            if (s1[j] != s2[j])
            {
                if ((check(graph, (int)s1[j] - (int)'A', (int)s2[j] - (int)'A') == 0))
                    graph[(int)s1[j] - (int)'A'].push_back((int)s2[j] - (int)'A');
                break;
            }
        }
        s1 = s2;
    }

    //graph_print(graph, n);

    toposort(n);

    for (int i = 0; i < n; i++)
    {
        int a = l.back();
        l.pop_back();
        cout << (char)(a + (int)'A');
    }
    cout << endl;

    return 0;
}