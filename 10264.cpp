#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
#define INF 10000000000
using namespace std;
vector<int> v;
int n, a;
int y[75536];
int cnt0(int x)
{
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if ((x & 1) == 0)
            ans++;
        x = (x >> 1);
    }
    return ans;
}
int bitdif(int a, int b)
{
    int x = ~(a ^ b);
    //cout<<a<<":"<<b<<":"<<abs(x)<<endl;

    return y[abs(x)];
}
vector<int> vv[32770];
int main()
{

    cin >> n;
    while (!cin.fail()) {
        v.clear();
        for (int i = 0; i < (1 << (n + 1)); i++)
            y[i] = cnt0(-i);

        for (int i = 0; i < (1 << n); i++) {
            cin >> a;
            v.push_back(a);
        }

        for (int i = 0; i < (1 << n); i++) {
            for (int j = i; j < (1 << n); j++) {
                if (bitdif(i, j) == 1) {
                    vv[i].push_back(j);
                    vv[j].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<int> u;
        for (int i = 0; i < (1 << n); i++) {
            u.push_back(0);
            for (int j = 0; j < vv[i].size(); j++) {
                u[i] += v[vv[i][j]];
            }
            //cout<<u[i]<<endl;;
        }
        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < (1 << n); j++) {
                if (bitdif(i, j) == 1) {
                    ans = max(ans, u[i] + u[j]);
                }
            }
        }
        cout << ans << "\n";
        cin >> n;
        for (int i = 0; i < (1 << n); i++)
            vv[i].clear();
    }
    return 0;
}
