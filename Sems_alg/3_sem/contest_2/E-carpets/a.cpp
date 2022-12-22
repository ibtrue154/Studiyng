#include <iostream>
#include <string>
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

void print_vector(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "i = " << i << "; ";
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }
}

void print_mas(int** mas, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << mas[i][j] << ' ';
        }
        cout << endl;
    }

    return;
}

int main()
{
    int n = 0, m = 0;
    int* adjac = new int[4];
    cin >> n >> m;

    string row;
    g.resize(n * m);
    comp.resize(n * m, 0);

    int** mas = new int*[n];
    for (int i = 0; i < n; i++)
    {
        mas[i] = new int[m];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> row;
        for (int j = 0; j < m; j++)
        {
            if ((int)row[j] == (int)'+')
            {
                mas[i][j] = 1;
            }
            else
            {
                mas[i][j] = 0;
            }
        }
    }

    //print_mas(mas, n, m);

    for (int i = 0; i < n * m; i++)
    {
        int a = i / n, b = i % m;
        adjac[0] = i + n;
        if (!((a + 1 < n) && (mas[a][b] == 1) && (mas[a + 1][b] == 1)))
        {
            adjac[0] = -1;
        }
        adjac[1] = i + 1;
        if (!((b + 1 < m) && (mas[a][b] == 1) && (mas[a][b + 1] == 1)))
        {
            adjac[1] = -1;
        }
        adjac[2] = i - n;
        if (!((a - 1 >= 0) && (mas[a][b] == 1) && (mas[a - 1][b] == 1)))
        {
            adjac[2] = -1;
        }
        adjac[3] = i - 1;
        if (!((b - 1 >= 0) && (mas[a][b] == 1) && (mas[a][b - 1] == 1)))
        {
            adjac[3] = -1;
        }

        for (int j = 0; j < 4; j++)
        {
            //cout << adjac[j] << " ";
            if (adjac[j] >= 0)
                g[i].push_back(adjac[j]);
        }
        if (mas[a][b] == 1)
        {
            g[i].push_back(i);
        }

        //cout << endl;
    }

    int num = 0;
    for (int v = 0; v < n * m; v++)
        if (!comp[v] && g[v].size() > 0)
            dfs(v, ++num);
    //print_vector(n * m);
    cout << num << endl;

    /*for (int i = 0; i < comp.size(); i++)
    {
        cout << comp[i] << ' ';
    }*/

    return 0;
}