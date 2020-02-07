#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
using namespace std;
vector<string> s[78];
int pre[1000005];
int main()
{
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i <= 10; i++)
            s[i].clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            string a;
            cin >> a;
            s[a.size()].push_back(a);
        }
        bool ok = 0;
        for (int i = 0; i <= 10 && !ok; i++) {
            sort(s[i].begin(), s[i].end());
            for (int j = 1; j < s[i].size(); j++) {
                if (s[i][j] == s[i][j - 1]) {
                    cout << "NO\n";
                    ok = 1;
                    break;
                }
            }
        }
        if (ok)
            continue;
        bool p = 0;
        for (int i = 0; i <= 10 && !p; i++) {
            for (int j = 0; j < s[i].size() && !p; j++) {
                for (int k = i + 1; k <= 10 && !p; k++) {
                    for (int t = 0; t < s[k].size() && !p; t++) {
                        int o = 0;
                        while (s[k][t][o] == s[i][j][o] && o < s[i][j].size())
                            o++;
                        if (o == s[i][j].size()) {
                            cout << "NO\n";
                            p = 1;
                        }
                    }
                }
            }
        }
        if (!p)
            cout << "YES\n";
    }
}
