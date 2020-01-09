#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
#define INF 10000000000
using namespace std;
int n;
int setbit(int a, int i, int x)
{
    int y = x << i;
    return a | y;
}
int cnt()
{
    int i = 0, j = 0, a = 0;
    while (n) {
        if (n & 1) {
            if (i % 2 == 0)
                a = setbit(a, j, n & 1);
            i++;
        }
        n = n >> 1;
        j++;
    }
    return a;
}
int main()
{

    cin >> n;
    while (n) {
        int x = n, a = cnt();
        cout << a << " " << x - a << "\n";
        cin >> n;
    }
    return 0;
}
