#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

int getMinSquares(int n)

{
    int* dp = new int[n + 1];

    dp[0] = 0;

    dp[1] = 1;

    dp[2] = 2;

    dp[3] = 3;

    for (int i = 4; i <= n; i++) {

        dp[i] = i;

        for (int x = 1; x <= (sqrt(i) / 1); x++) {

            int temp = x * x;

            if (temp > i)

                break;

            else

                dp[i] = min(dp[i], 1 + dp[i - temp]);

        }

    }

    int res = dp[n];

    delete[] dp;

    return res;

}

int main()

{
    int a = 0;
    cin >> a;
    cout << getMinSquares(a);

    return 0;

}