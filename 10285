#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
#define INF 10000000000
using namespace std;
long long int arr[115][115];
long long int dp[115][115];
long long int cnt(int i, int j)
{
    if (dp[i][j] + 1)
        return dp[i][j];
    long long int ans = 1;
    if ((arr[i][j] > arr[i - 1][j]))
        ans = max(ans, (cnt(i - 1, j) + 1));
    if (arr[i][j] > arr[i + 1][j])
        ans = max(ans, (1 + cnt(i + 1, j)));
    if (arr[i][j] > arr[i][j + 1])
        ans = max(ans, (1 + cnt(i, j + 1)));
    if (arr[i][j] > arr[i][j - 1])
        ans = max(ans, (1 + cnt(i, j - 1)));
    return dp[i][j] = ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        int n, m;
        cin >> s >> n >> m;
        for (int i = 0; i <= n + 10; i++) {
            for (int j = 0; j <= m + 10; j++) {
                arr[i][j] = INF;
                dp[i][j] = -1;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> arr[i][j];
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ans = max(ans, cnt(i, j));
            }
        }
        cout << s << ": " << ans << "\n";
    }
    return 0;
}
