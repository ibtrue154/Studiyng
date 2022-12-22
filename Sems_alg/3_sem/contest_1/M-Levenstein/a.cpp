#include <algorithm>
#include <vector>
#include <cstdio>
#include <string.h>
#include <iostream>

//template<typename T>
int LevenshteinDistance(std::string source, std::string target) 
{
    if (source.length() > target.length()) 
    {
        return LevenshteinDistance(target, source);
    }

    const int min_size = source.length(), max_size = target.length();
    std::vector<int> lev_dist(min_size + 1);

    for (int i = 0; i <= min_size; ++i) 
    {
        lev_dist[i] = i;
    }

    for (int j = 1; j <= max_size; ++j) 
    {
        int previous_diagonal = lev_dist[0], previous_diagonal_save;
        ++lev_dist[0];

        for (int i = 1; i <= min_size; ++i) 
        {
            previous_diagonal_save = lev_dist[i];
            if (source[i - 1] == target[j - 1]) 
            {
                lev_dist[i] = previous_diagonal;
            } 
            else 
            {
                lev_dist[i] = std::min(std::min(lev_dist[i - 1], lev_dist[i]), previous_diagonal) + 1;
            }
            previous_diagonal = previous_diagonal_save;
        }
    }

    return lev_dist[min_size];
}

int main()
{
    std::string a, b;

    std::cin >> a >> b;

    int distance = LevenshteinDistance(a, b);

    printf("%d", distance);
    return 0;
}