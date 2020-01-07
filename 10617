#include <bits/stdc++.h>
#define INF 10000000
#define ms(x, a) memset(x, a, sizeof(x))
using namespace std;
string s;
long long int dp[63][63];
long long int cnt(int i, int j)
{
    if (dp[i][j] + 1)
        return dp[i][j];
    if (i > j)
        return 0;
    if (i == j)
        return dp[i][j] = 1;
    if (i + 1 == j)
        return dp[i][j] = (s[i] == s[j]) + 2;
    long long int ans = 0;
    ans += cnt(i + 1, j) + cnt(i, j - 1) - cnt(i + 1, j - 1);
    if (s[i] == s[j]) {
        ans += cnt(i + 1, j - 1) + 1;
    }
    return dp[i][j] = ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        ms(dp, -1);
        cin >> s;
        cout << cnt(0, s.size() - 1) << endl;
    }
}
