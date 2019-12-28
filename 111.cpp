#include <bits/stdc++.h>
using namespace std;
int n, a;
int v[50], t[50];
int dp[50][50];
int cnt(int i, int j)
{
    if (i == n + 1 || j == n + 1)
        return 0;
    if (dp[i][j] + 1)
        return dp[i][j];
    return dp[i][j] = max((t[j] == v[i]) * (cnt(i + 1, j + 1) + 1), max(cnt(i + 1, j), cnt(i, j + 1)));
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        v[a] = i;
    }
    cin >> a;
    while (!cin.fail()) {
        memset(dp, -1, sizeof(dp));
        t[a] = 1;
        for (int i = 2; i <= n; i++) {
            cin >> a;
            t[a] = i;
        }
        cout << cnt(1, 1) << endl;

        cin >> a;
    }
}
