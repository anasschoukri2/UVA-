#include <bits/stdc++.h>
#define INF 102222222
#define long long int ll
using namespace std;
int main()
{
    string a, b;
    getline(cin, a);
    int k = 1;
    while (a != "#") {
        int dp[4000][1000];
        memset(dp, 0, sizeof(dp));
        getline(cin, b);
        int ans = 0;
        for (int i = 1; i <= a.size(); i++) {
            for (int j = 1; j <= b.size(); j++) {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
                ans = max(ans, dp[i][j]);
            }
        }
        printf("Case #%d: you can visit at most %d cities.\n", k, ans);
        k++;
        getline(cin, a);
    }
}
