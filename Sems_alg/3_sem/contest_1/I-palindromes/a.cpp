#include <iostream>
#include <string>

int sum(int** matr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += matr[i][j];
        }
    }

    return sum;
}

void print(int** matr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << matr[i][j] << ' ';
        }
        std::cout << std::endl;
        
    }
    std::cout << std::endl;
}

int main()
{
    std::string str;
    std::cin >> str;

    int** a = new int*[str.size() + 2];
    for (int i = 0; i < str.size() + 2; i++)
        a[i] = new int[str.size() + 2];


    for (int i = 1; i <= str.size(); i++)
    {
        for (int j = i + 1; j <= str.size(); j++)
        {
            if ((int)str[i] == (int)str[j])
            {
                a[i][j] = a[i + 1][j] + a[i][j - 1] + 1;
            }
            else
            {
                a[i][j] = a[i + 1][j] + a[i][j - 1] - a[i + 1][j - 1];
            }
        }
    }

    print(a, str.size() + 2);

    int res = sum(a, str.size() + 2);

    std::cout << res << std::endl;

    return 0;
}