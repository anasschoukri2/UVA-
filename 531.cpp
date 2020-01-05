#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
using namespace std;
vector<string> a, b;
int dp[107][107];
int main()
{
    string s;
    cin >> s;
    while (!cin.fail()) {
        a.clear();
        b.clear();
        ms(dp, 0);
        while (s[0] != '#') {
            a.push_back(s);
            cin >> s;
        }
        cin >> s;
        while (s[0] != '#') {
            b.push_back(s);
            cin >> s;
        }
        cin >> s;
        int ans = 0;
        for (int i = 1; i <= a.size(); i++)
            for (int j = 1; j <= b.size(); j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                dp[i][j] = max(dp[i][j - 1], dp[i][j]);
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
                ans = max(ans, dp[i][j]);
            }

        stack<string> ss;
        for (int i = a.size(); i >= 1; i--)
            for (int j = b.size(); j >= 1; j--)
                if (dp[i][j] == ans && dp[i - 1][j - 1] == ans - 1 && a[i - 1] == b[j - 1]) {
                    ss.push(a[i - 1]);
                    ans--;
                }

        while (!ss.empty()) {
            cout << ss.top();
            ss.pop();
            if (ss.empty())
                cout << endl;
            else
                cout << " ";
        }
    }
}
