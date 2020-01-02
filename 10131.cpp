#include <bits/stdc++.h>
#define INF 102222222
#define long long int ll
using namespace std;
typedef pair<int, int> iii;
typedef pair<iii, int> ii;
vector<ii> v;
int dp[4000];
int cnt(int i, int j)
{
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i; j < v.size(); j++) {
            if (v[j].first.second > v[i].first.second) {
                dp[j] = max(dp[j], dp[i] + 1);
                ans = max(ans, dp[j]);
            }
        }
    }
    return ans + 1;
}
int main()
{
    int a, b;
    cin >> a >> b;
    int o = 1;
    while (!cin.fail()) {
        iii y = { a, b };
        ii u = { y, o };
        v.push_back(u);
        o++;
        cin >> a >> b;
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int ans = cnt(0, 0);
    cout << ans << endl;
    int j = v.size() - 1;
    stack<int> s;
    while (ans) {
        if (dp[j] == ans - 1) {
            cout << v[j].second << "\n";
            ans--;
        }
        j--;
    }
}
