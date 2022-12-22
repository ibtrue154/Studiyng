#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

bool kv(int x)
{
    int a = sqrt(x);
    return (a * a == x);
}
 
int f(int n)
{
    if (kv(n)) {
        return 1;
    }

    for (int i = 1; i <= sqrt(n)+1; i++) {
        if (kv(n - (i * i))) {
            return 2;
        }
    }
 
    while (n % 4 == 0) {
        n >>= 2;
    }
    if (n % 8 == 7) {
        return 4;
    }
 
    return 3;
}
 
int main()
{
    int a = 0;
    cin >> a;
    cout << f(a) << endl;
    return 0;
}