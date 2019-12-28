#include <bits/stdc++.h>
using namespace std;
int n, a;
int v[50], t[50];
int dp[50][50];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        v[a] = i;
    }
    cin >> a;
    while (!cin.fail()) {
        t[a] = 1;
        for (int i = 2; i <= n; i++) {
            cin >> a;
            t[a] = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = max((t[j] == v[i]) * (dp[i - 1][j - 1] + 1), max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        cout << dp[n][n] << endl;
        cin >> a;
    }
}
