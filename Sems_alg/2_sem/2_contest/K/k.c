#include <stdio.h>
#include <stdlib.h>


int cmp(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

void sym_diff(int* first, int* second, int n, int m)
{
    qsort(first, n, sizeof(int), cmp);
    qsort(second, m, sizeof(int), cmp);
    int left = 0, right = 0;
    while(left < n || right < m)
    {
        while(left < n && (right >= m || first[left] < second[right]) )
        {
            printf("%d ", first[left]);
            left++;
        }
        while(right < m && (left >= n || second[right] < first[left]))
        {
            printf("%d ", second[right]);
            right++;
        }
        if(left < n && right < m)
        {
            if(first[left] == second[right])
            {
                left++; right++;
            }
        }
    }
}

int main()
{
    int first[100001], second[100001];
    int count = 0, n = 0, m = 0;
    while(1)
    {
        int x;
        scanf("%d", &x);
        if(x != 0)
        {
            if(!count)
            {
                first[n] = x;
                n++;
            }
            else
            {
                second[m] = x;
                m++;
            }
        }
        else
        {
            count++;
            if(count == 2)
                break;
        }
    }
    sym_diff(first, second, n, m);
    return 0;
}