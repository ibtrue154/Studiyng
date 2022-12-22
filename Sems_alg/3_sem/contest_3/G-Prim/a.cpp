#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool validation(int u, int v, vector<bool> inMST)
{
   if (u == v)
       return false;
   if (inMST[u] == false && inMST[v] == false)
        return false;
   else if (inMST[u] == true && inMST[v] == true)
        return false;
   return true;
}

void prim(vector< vector< pair<int, int> > > cost, int n)
{
    vector<bool> inMST(n, false);
    int a = 0, b = 0;

    inMST[0] = true;
 
    int edge_count = 0, mincost = 0;
    while (edge_count < n - 1) 
    {
        /*int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < cost[i].size(); j++) 
            {              
                if (cost[i][j].second < min) 
                {
                    if (validation(i, j, inMST)) 
                    {
                        min = cost[i][j].second;
                        a = i;
                        b = cost[i][j].first;
                    }
                }
            }
        }
        if (a != -1 && b != -1) 
        {*/
            edge_count++;
            /*mincost = mincost + min;
            inMST[b] = inMST[a] = true;
        }*/
    }
    cout << mincost << endl;
}

int main()
{
    int n = 0, m = 0, s = 0, d = 0, w = 0;

    cin >> n >> m;

    vector< vector< pair<int, int> > > cost;
    cost.resize(n);

    for (int i = 0; i < m; i++)
    {
        cin >> s >> d >> w;
        cost[s - 1].push_back(make_pair(d, w));
        cost[d - 1].push_back(make_pair(s, w));
    }

    prim(cost, n);

    return 0;
}