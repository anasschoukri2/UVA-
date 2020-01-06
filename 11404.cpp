#include <bits/stdc++.h>
#define INF 10000000
#define ms(x, a) memset(x, a, sizeof(x))
using namespace std;
string s;
int dp[1020][1020];
int cnt(int i, int j)
{
    if (dp[i][j] + 1)
        return dp[i][j];
    if (i > j)
        return dp[i][j] = 0;
    if (i == j)
        return dp[i][j] = 1;
    return dp[i][j] = max((s[i] == s[j]) * (cnt(i + 1, j - 1) + 2), max(cnt(i + 1, j), cnt(i, j - 1)));
}
int main()
{
    cin >> s;
    while (!cin.fail()) {
        ms(dp, -1);
        int ans = cnt(0, s.size() - 1);
        string a = "", b = "";
        int lasti = -1, lastj = s.size();
        while (ans && ans + 1) {
            string k = "{}";
            int tempi = lasti, tempj = lastj;
            for (int i = lasti + 1; i < s.size(); i++) 
                for (int j = lastj - 1; j >= i; j--) 
                    if (dp[i][j] == ans && dp[i + 1][j - 1] == ans - 2 && s[i] == s[j] && lasti < i && lastj > j && k[0] > s[i]) {
                        k[0] = s[i];
                        k[1] = s[i];
                        tempj = j;
                        tempi = i;
                    }
            if (k[0] != '{') {
                if (k[1] == k[0]) {
                    b = " " + b;
                    b[0] = k[0];
                    lastj = tempj;
                    lasti = tempi;
                    ans -= 2;
                }
            }
        }
        a = b;
        reverse(a.begin(), a.end());
        cout << a;
        for (int i = (cnt(0, s.size() - 1) % 2 != 0); i < b.size(); i++)
            cout << b[i];
        cout << endl;
        cin >> s;
    }
}
