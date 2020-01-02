#include <bits/stdc++.h>
#define INF 8222222222
using namespace std;
typedef pair<int, int> ii;
vector<ii> v;
long long int dp[40][40];
int uu[40][40];
long long int cnt(int i, int j)
{
    if (i > j)
        return INF;
    if (i == j)
        return 0;
    long long int ans = dp[i][j];
    if (ans != -1)
        return ans;
    ans = INF;
    int l = -1;
    for (int k = i; k < j; k++) {
        long long int a = cnt(i, k), b = cnt(k + 1, j), c = (v[i].first * v[k].second * v[j].second);
        if (a + b + c < ans) {
            ans = a + b + c;
            l = k;
        }
    }
    uu[i][j] = l;
    return ans;
}
void printpath(int i, int j)
{
    if (i == j) {
        cout << "A" << i + 1;
        return;
    }
    cout << '(';
    printpath(i, uu[i][j]);
    cout << " x ";
    printpath(uu[i][j] + 1, j);
    cout << ")";
}
int main()
{
    int n;
    cin >> n;
    int k = 1;
    while (n) {
        v.clear();
        memset(dp, -1, sizeof(dp));
        memset(uu, 0, sizeof(uu));
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back({ a, b });
        }
        cnt(0, v.size() - 1);
        cout << "Case " << k << ": ";
        printpath(0, v.size() - 1);
        cout << "\n";
        cin >> n;
        k++;
    }
}
