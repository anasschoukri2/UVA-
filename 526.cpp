#include <bits/stdc++.h>
#define INF 10000000
#define ms(x, a) memset(x, a, sizeof(x))
using namespace std;
string a, b;
long long int dp[123][163];
long long int cnt(int i, int j)
{
    if (dp[i][j] + 1)
        return dp[i][j];
    if (i == a.size())
        return dp[i][j] = b.size() - j;
    if (j == b.size())
        return dp[i][j] = a.size() - i;
    long long int ans = INF;
    ans = min(ans, cnt(i + 1, j + 1));
    if (a[i] != b[j]) {
        ans++;
    }
    return dp[i][j] = min(ans, min(cnt(i + 1, j) + 1, cnt(i, j + 1) + 1));
}
int indx = 1, u;

void cnt1(int i, int j)
{
    if (i == a.size()) {
        for (int k = j; k < b.size(); k++) {
            u++;
            cout << u << " Insert " << indx << "," << b[k] << endl;
            indx++;
        }
    }
    else if (j == b.size()) {
        for (int k = i; k < a.size(); k++) {
            u++;
            cout << u << " Delete " << indx << endl;
        }
    }
    else if (dp[i][j] == cnt(i + 1, j) + 1) {
        u++;
        cout << u << " Delete " << indx << endl;
        cnt1(i + 1, j);
    }
    else if (dp[i][j] == cnt(i, j + 1) + 1) {
        u++;
        cout << u << " Insert " << indx << "," << b[j] << endl;
        indx++;
        cnt1(i, j + 1);
    }
    else if (dp[i][j] == cnt(i + 1, j + 1) + 1) {
        u++;
        cout << u << " Replace " << indx << "," << b[j] << endl;
        indx++;
        cnt1(i + 1, j + 1);
    }
    else if (dp[i][j] == cnt(i + 1, j + 1)) {
        indx++;
        cnt1(i + 1, j + 1);
    }
}
int main()
{

    getline(cin, a);
    getline(cin, b);
    while (1) {
        indx = 1;
        u = 0;
        ms(dp, -1);
        cout << cnt(0, 0) << endl;
        cnt1(0, 0);
        getline(cin, a);
        getline(cin, b);
        if (cin.fail())
            return 0;
        cout << endl;
    }
}
