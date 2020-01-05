#include <bits/stdc++.h>
#define INF 10000000
#define ms(x, a) memset(x, a, sizeof(x))
using namespace std;
int n, m, t;
typedef pair<int, int> ii;
int dp[20000];
int cnt(int sum)
{
    if (sum > t)
        return -INF;
    if (dp[sum] + 1)
        return dp[sum];
    if (sum == t)
        return dp[sum] = 0;
    return dp[sum] = max(max(0, cnt(sum + n) + n), max(0, cnt(sum + m) + m));
}
int k;
int cnt2(int sum)
{
    if (sum > k)
        return -INF;
    if (dp[sum] + 1)
        return dp[sum];
    if (sum == k)
        return dp[sum] = 0;
    return dp[sum] = max(cnt2(sum + n) + 1, cnt2(sum + m) + 1);
}
int main()
{
    cin >> n;
    while (!cin.fail()) {
        ms(dp, -1);
        cin >> m >> t;
        int ans = cnt(0);
        k = ans;
        ms(dp, -1);
        cout << cnt2(0);
        if (t - ans)
            cout << " " << t - ans;
        cout << "\n";
        cin >> n;
    }
}
