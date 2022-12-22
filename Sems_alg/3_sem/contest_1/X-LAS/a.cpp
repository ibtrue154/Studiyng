#include <iostream>
#include <climits>

int upper_bound(int* sub, int left, int right, int key)
{
    int mid = 0;
    int l = left;
    int r = right;
    int ceilIndex = 0;
    bool ceilIndexFound = false;

    for (mid = (left + right) / 2; left <= right && !ceilIndexFound; mid = (left + right) / 2) 
    {
        if (sub[mid] > key) 
        {
            right = mid - 1;
        }
        else if (sub[mid] == key) 
        {
            ceilIndex = mid;
            ceilIndexFound = true;
        }
        else if (mid + 1 <= right && sub[mid + 1] >= key) 
        {
            sub[mid + 1] = key;
            ceilIndex = mid + 1;
            ceilIndexFound = true;
        }
        else 
        {
            left = mid + 1;
        }
    }

    if (!ceilIndexFound) 
    {
        if (mid == left) 
        {
            sub[mid] = key;
            ceilIndex = mid;
        }
        else 
        {
            sub[mid + 1] = key;
            ceilIndex = mid + 1;
        }
    }

    return ceilIndex;
}

int main()
{
    int N = 0, ans = -1;
    scanf("%d", &N);
    
    int* mas = new int[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &mas[i]);
    }

    int* idx = new int[N];
    int* sub = new int[N];

    for (int i = 0; i < N; i++)
    {
        idx[i] = INT_MAX;
        sub[i] = INT_MAX;
    }

    sub[0] = mas[0];
    idx[0] = 0;

    for (int i = 1; i < N; i++)
    {
        idx[i] = upper_bound(sub, 0, i, mas[i]);
        if (ans < idx[i])
        {
            ans = idx[i];
        }
    }

    int* res = new int[ans + 1];
    int a = 0, b = 0;

    for (int i = N - 1; i > -1; i--)
    {
        if (idx[i] == ans - a)
        {
            res[b] = i;
            a++;
            b++;
        }
    }

    /*std::cout << "idx: ";

    for (int i = 0 ; i < N; i++)
    {
        std::cout << idx[i] << ' ';
    }
    std::cout << std::endl;

    std::cout << "res: ";*/

    std::cout << ans + 1 << ' ';

    for (int i = ans; i > -1; i--)
    {
        std::cout << res[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}