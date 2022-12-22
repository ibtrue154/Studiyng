#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = 0, pow = 1, t = k;

    while(pow * 10 <= k)
    {
        pow *= 10;
    }
    
    int a = pow;
    
    while(pow >= 1)
    {
        ans += (k - pow + 1);
        pow /= 10;
        k /= 10;
    }
    
    pow = a;
    k = t;
    
    if(k != pow)
    {
        while(1) 
        {
            pow *= 10;
            if (pow > n)
            {
                break;
            }
            k *= 10;
            if(n < k)
            {
                ans += (n - pow + 1);
                break;
            }
            else
            {
                ans += (k - pow);
            }
        }
    }
    
    printf("%d", ans);
    return 0;
}