#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector< vector<int> > g;

int main()
{
    int n = 0;
    int*  adjac = new int[8];
    cin >> n;
    g.resize(n * n);
    for (int i = 0; i < n * n; i++)
    {
        int a = i / n, b = i % n;
        adjac[0] = i + 2 * n - 1;
        if (!(a + 2 < n && b - 1 >= 0))
        {
            adjac[0] = -1;
        }
        adjac[1] = i + 2 * n + 1;
        if (!(a + 2 < n && b + 1 < n))
        {
            adjac[1] = -1;
        }
        adjac[2] = i + n + 2;
        if (!(a + 1 < n && b + 2 < n))
        {
            adjac[2] = -1;
        }
        adjac[3] = i - n + 2;
        if (!(a - 1 >= 0 && b + 2 < n))
        {
            adjac[3] = -1;
        }
        adjac[4] = i - 2 * n + 1;
        if (!(a - 2 >= 0 && b + 1 < n))
        {
            adjac[4] = -1;
        }
        adjac[5] = i - 2 * n - 1;
        if (!(a - 2 >= 0 && b - 1 >= 0))
        {
            adjac[5] = -1;
        }
        adjac[6] = i - n - 2;
        if (!(a - 1 >= 0 && b - 2 >= 0))
        {
            adjac[6] = -1;
        }
        adjac[7] = i + n - 2;
        if (!(a + 1 < n && b - 2 >= 0))
        {
            adjac[7] = -1;
        }
        cout << "i = " << i << "; ";
        for (int j = 0; j < 8; j++)
        {
            cout << adjac[j] << " ";
            if (adjac[j] >= 0)
                g[i].push_back(adjac[j]);
        }

        cout << endl;
    }

    return 0;
}