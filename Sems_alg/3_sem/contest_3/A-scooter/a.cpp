#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
 
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {1, -1, 0, 0};
int n = 0, m = 0;
 
bool Okey(int x, int y){
    if(x < 0 || y < 0 || x >= n || y >= m)
        return 0;
    return 1;
}

void find_min(int** min_cost, int** a)
{
	priority_queue< pair< int, pair< int, int > >, vector< pair< int, pair< int, int > > >, greater< pair< int, pair< int, int > > > > q;
    q.push({0, {0, 0}});
    min_cost[0][0] = 0;
    while(!q.empty())
	{
        pair< int, pair< int, int > > cur = q.top();
        int pos_x = cur.second.first;
        int pos_y = cur.second.second;
        q.pop();
        for(int i = 0; i < 4; i++)
		{
            int new_x = dx[i] + pos_x;
            int new_y = dy[i] + pos_y;
            if(Okey(new_x, new_y) == 1)
			{
                int sum = min_cost[pos_x][pos_y] + (-1) * min(0, a[pos_x][pos_y] - a[new_x][new_y]);
                if(sum < min_cost[new_x][new_y])
				{
                    min_cost[new_x][new_y] = sum;
                    q.push({sum, {new_x, new_y}});
                }
            }
        }
    }
 
    cout << min_cost[n - 1][m - 1];
}
 
int main()
{
    cin >> n >> m;
    int** a = new int*[n];
    int** min_cost = new int*[m];
    for(int i = 0; i < n; i++)
	{
        a[i] = new int[m];
        min_cost[i] = new int[m];
        for(int j = 0; j < m; j++)
		{
            cin >> a[i][j];
            min_cost[i][j] = (int)1000000000;
        }
    }
 
    return 0;
}