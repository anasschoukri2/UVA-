#include <bits/stdc++.h>
#define INF 10400000
using namespace std;
int dp[1500][1500];
bool p[1500];
int f[1500];
int cnt(int i, int j)
{
    if (f[j] - f[i] <= 1)
        return 0;
    int& t = dp[i][j];
    if (t + 1)
        return t;
    t = INF;
    for (int k = i + 1; k < j; k++) {
        if (p[k]) {
            t = min(t, cnt(i, k) + cnt(k, j) + j - i);
        }
    }
    return t;
}
int main()
{
    int l, n, a;
    cin >> l;
    while (l != 0) {
        memset(dp, -1, sizeof(dp));
        memset(p, 0, sizeof(p));
        memset(f, 0, sizeof(p));
        cin >> n;
        f[0] = 0;
        f[l] = n + 1;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            f[a] = i;
            p[a] = true;
        }
        printf("The minimum cutting is %d.\n", cnt(0, l));
        cin >> l;
    }
}
