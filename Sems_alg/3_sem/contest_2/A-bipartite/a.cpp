#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    vector< vector<int> > g;
    int n = 0, m = 0, s = 0, d = 0;
    scanf("%d %d", &n, &m);

    g.resize(n);

    for (int c = 0; c < m; c++)
    {
        scanf("%d %d", &s, &d);
        g[s].push_back(d);
        g[d].push_back(s);
    }

    vector<char> part (n, -1);
    bool ok = true;
    vector<int> q (n);
    for (int st = 0; st < n; ++st)
	    if (part[st] == -1) 
        {
		    int h = 0, t = 0;
            q[t++] = st;
            part[st] = 0;
            while (h < t) 
            {
                int v = q[h++];
                for (int i = 0; i < g[v].size(); ++i) 
                {
                    int to = g[v][i];
                    if (part[to] == -1)
                        part[to] = !part[v],  q[t++] = to;
                    else
                        ok &= part[to] != part[v];
                }
            }
	}

    puts (ok ? "YES" : "NO");

    return 0;
}