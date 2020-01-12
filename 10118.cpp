#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
#define INF 100000000
#define MOD 1000000007
using namespace std;
stack<int> s[5];
pair<int, bool> setbit(int mask, int i)
{
    if ((mask >> i) & 1) {
        return { ~(1 << i) & mask, 1 };
    }
    return { (1 << i) | mask, 0 };
}
int cntbit(int mask)
{
    int ans = 0;
    while (mask) {
        ans += (mask & 1);
        mask >>= 1;
    }
    return ans;
}
map<vector<int>, int> dp;
int cnt(int basket)
{
    if (cntbit(basket) >= 5)
        return 0;
    vector<int> u;
    for (int i = 0; i < 4; i++)
        u.push_back(s[i].size());
    u.push_back(basket);
    if (dp[u])
        return dp[u];
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        if (!s[i].empty()) {
            int a = s[i].top();
            s[i].pop();
            pair<int, int> x = setbit(basket, a - 1);
            ans = max(ans, cnt(x.first) + x.second);
            s[i].push(a);
        }
    }
    return dp[u] = ans;
}
int main()
{
    int n;
    cin >> n;
    while (n) {
        vector<int> v[5];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                int a;
                cin >> a;
                v[j].push_back(a);
            }
        }
        for (int i = 3; i >= 0; i--) {
            while (!s[i].empty())
                s[i].pop();
            for (int j = v[i].size() - 1; j >= 0; j--) {
                s[i].push(v[i][j]);
            }
        }
        cout << cnt(0) << "\n";
        dp.clear();
        cin >> n;
    }
    return 0;
}
