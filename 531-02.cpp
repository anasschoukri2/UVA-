#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
using namespace std;
vector<string> a, b;
int dp[107][107];
int ans = 0;
int cnt(int i, int j)
{
    if (dp[i][j] + 1)
        return dp[i][j];
    if (i == a.size() || j == b.size())
        return dp[i][j] = 0;
    return ans = dp[i][j] = max((a[i] == b[j]) * (cnt(i + 1, j + 1) + 1), max(cnt(i, j + 1), cnt(i + 1, j)));
}
int main()
{
    string s;
    cin >> s;
    while (!cin.fail()) {
        a.clear();
        b.clear();
        ms(dp, -1);
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
        cnt(0, 0);
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < b.size(); j++)
                if (dp[i][j] == ans && dp[i + 1][j + 1] == ans - 1 && a[i] == b[j]) {
                    cout << a[i];
                    ans--;
                    if (ans != 0)
                        cout << " ";
                    break;
                }

        cout << endl;
    }
}
