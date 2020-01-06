#include <bits/stdc++.h>
#define INF 10000000
#define ms(x, a) memset(x, a, sizeof(x))
using namespace std;
string s;
int dp[1020][1020];
int cnt(int i, int j)
{
    if (i >= j)
        return 0;
    if (dp[i][j] + 1)
        return dp[i][j];
    return dp[i][j] = min((s[i] == s[j]) * cnt(i + 1, j - 1) + (s[i] != s[j]) * INF, min(cnt(i + 1, j), min(cnt(i, j - 1), cnt(i + 1, j - 1))) + 1);
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s;
        ms(dp, -1);
        printf("Case %d: %d\n", i + 1, cnt(0, s.size() - 1));
    }
}
