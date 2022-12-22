#include <string>
#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>

int main()
{
    int N = 0;
    scanf("%d", &N);
    
    int* mas = new int[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &mas[i]);
    }

    std::vector<int> d(N);
    std::vector<int> p(N);
    d[0] = INT_MIN;
    for (int i = 1; i <= N; ++i)
	    d[i] = INT_MAX;

    for (int i = 0; i < N; i++) 
    {
        //p[i] = -1;
        int j = std::upper_bound(d.begin(), d.end(), mas[i]) - d.begin();
        if (d[j - 1] < mas[i] && mas[i] < d[j])
        {
            d[j] = mas[i];
            //p[i] = j;
        }
    }

    for (int i = 0; i < d.size(); i++)
    {
        std::cout << d[i] << ' ';
    }
    std::cout << std::endl;

    int ans = 0, i = 0;
    for (int i = 1; i <= N; i++)
    {
        if (d[i] > INT_MIN && d[i] < INT_MAX)
        {
            ans = i;
        }
    }

    std::cout << ans << ' ';

    std::cout << std::endl;

    return 0;
}