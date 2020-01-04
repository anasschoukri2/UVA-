#include <bits/stdc++.h>
#define INF 102222222
#define ll unsigned long long int
#define ms(x, a) memset(x, a, sizeof(x))
using namespace std;
vector<int> v;
int dp[27][100000];
bool ex[27][100000 + 10];
int n;
int cnt(int i, int sum)
{

    if (sum > n)
        return -INF;
    ex[i][sum] = true;
    if (i == v.size() || sum == n)
        return 0;
    if (dp[i][sum] != -1)
        return dp[i][sum];
    int& t = dp[i][sum];
    t = 0;
    return t = max(cnt(i + 1, sum + v[i]) + v[i], cnt(i + 1, sum));

}
int main()
{
    //5 3 1 3 4
    cin >> n;
    while (!cin.fail()) {
        int k;
        ms(dp, -1);
        v.clear();
        cin >> k;
        while (k--) {
            int a;
            cin >> a;
            v.push_back(a);
        }

        reverse(v.begin(), v.end());
        ms(ex, 0);
        int ans = cnt(0, 0);
        int j = 0;

        for (int i = v.size() - 1; i >= 0; i--) {
            if (ex[i][ans - v[i]] && ans - v[i] >= 0) {
                cout << v[i] << " ";
                ans -= v[i];
            }
        }

        cout << "sum:" << dp[0][0] << endl;
        cin >> n;
    }
}
