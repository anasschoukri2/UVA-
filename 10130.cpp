#include <bits/stdc++.h>
#define INF 102222222
#define ll unsigned long long int
#define ms(x, a) memset(x, a, sizeof(x))
using namespace std;
typedef pair<int, int> ii;
vector<ii> v;
vector<int> cartable;
int dp[1007][50];
int cnt(int i, int sum, int w)
{
    if (sum > w)
        return -INF;
    if (i == v.size() || w == sum) {
        return 0;
    }
    if (dp[i][sum] + 1)
        return dp[i][sum];
    return dp[i][sum] = max(cnt(i + 1, sum, w), cnt(i + 1, sum + v[i].second, w) + v[i].first);
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        v.clear();
        int p, c;
        cin >> p;
        for (int i = 0; i < p; i++) {
            int pr, wi;
            cin >> pr >> wi;
            v.push_back({ pr, wi });
        }
        cin >> c;
        int ans = 0;
        for (int i = 0; i < c; i++) {
            int a;
            cin >> a;
            ms(dp, -1);
            ans += cnt(0, 0, a);
        }
        cout << ans << endl;
    }
}
