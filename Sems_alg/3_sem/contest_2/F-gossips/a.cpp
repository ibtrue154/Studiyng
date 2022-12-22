#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector< vector<bool> > used;
vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

/*long long int bfs(long long int s, long long int to, long long int n) 
{
    queue<long long int> q;
    q.push (s);
    vector<long long int> d (n), p (n);
    p[s] = -1;
    long long int len = 0;
    while (!q.empty()) {
        long long int v = q.front();
        q.pop();
        for (size_t i=0; i<g[v].size(); ++i) {
            long long int to = g[v][i];
            if (!used[to]) {
                used[to] = true;
                q.push (to);
                d[to] = d[v] + 1;
                p[to] = v;
            }
        }
    }
    for (long long int v=to; v!=-1; v=p[v])
		len++;
    return len;
}*/

bool check(int x, int y, int n, int m)
{
    if(x < 0 || y < 0 || x >= n || y >= m)
        return 0;
    if(used[x][y])
        return 0;
    return 1;
}

int main()
{
    int n, m; cin >> n >> m;
    int k; cin >> k;
    used = vector< vector< bool > >(n);
    for(int i = 0; i < n; i++)
    {
        used[i] = vector< bool >(m);
    }
    queue< pair< int, pair< int, int > > > q;
    for(int i = 0; i < k; i++)
    {
        int x, y; cin >> x >> y;
        q.push({0, {x, y}});
        used[x][y] = 1;
    }
    int ans = 0;
    while(!q.empty())
    {
        pair< int, pair< int, int > > cur = q.front();
        q.pop();
        ans = max(ans, cur.first);
        for(int i = 0; i < 4; i++)
        {
            pair< int, int > par = {dx[i] + cur.second.first, dy[i] + cur.second.second};
            if(check(par.first, par.second, n, m))
            {
                used[par.first][par.second] = 1;
                q.push({cur.first + 1, par});
            }
        }
    }
    cout << ans;

    return 0;
}