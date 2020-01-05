#include <bits/stdc++.h>
#define INF 102222222
#define ll unsigned long long int
#define ms(x, a) memset(x, a, sizeof(x))
using namespace std;
vector<int> v;
int dp[100][50000];
int cnt(int i, int sum1, int sum2)
{
    if (i == v.size())
        return abs(sum1 - sum2);
    if (dp[i][sum1] + 1)
        return dp[i][sum1];
    return dp[i][sum1] = min(cnt(i + 1, sum1 + v[i], sum2), cnt(i + 1, sum1, sum2 + v[i]));
}
int main()
{
    int t;
    cin >> t;

    while (t--) {
        ms(dp, -1);
        int n;
        cin >> n;
        v.clear();
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v.push_back(a);
        }
        cout << cnt(0, 0, 0) << endl;
    }
}
