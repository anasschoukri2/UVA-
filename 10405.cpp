#include <bits/stdc++.h>
using namespace std;
string a, b;
long long int dp[1004][1004];
long long int cnt(long long int i, long long int j)
{
    if (i == a.size() || j == b.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    return dp[i][j] = max((a[i] == b[j]) * (cnt(i + 1, j + 1) + 1), max(cnt(i, j + 1), cnt(i + 1, j)));
}
int main()
{
    getline(cin, a);
    while (!cin.fail()) {
        memset(dp, -1, sizeof(dp));
        getline(cin, b);
        cout << cnt(0, 0) << '\n';
        getline(cin, a);
    }
}
