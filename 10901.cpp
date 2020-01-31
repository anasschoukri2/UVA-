#include <bits/stdc++.h>
using namespace std;
int main()
{
    int u;
    cin >> u;
    while (u--) {
        int n, t, m;
        cin >> n >> t >> m;
        bool ship = 0;
        int ans[100005];
        queue<pair<int, int> > b[2];
        for (int i = 0; i < m; i++) {
            int x;
            string s;
            cin >> x >> s;
            b[(s != "left")].push({ x, i });
        }
        int k = 0;
        while (!b[0].empty() || !b[1].empty()) {
            int x = 154854848;
            if (!b[0].empty()) {
                x = b[0].front().first;
            }
            if (!b[1].empty()) {
                x = min(x, (int)b[1].front().first);
            }
            k = max(k, x);
            int car = 0;
            if (b[ship].front().first <= k) {
                while (b[ship].front().first <= k && !b[ship].empty() && car < n) {
                    ans[b[ship].front().second] = k + t;
                    car++;
                    b[ship].pop();
                }
                k += t;
                ship = !ship;
            }
            else if (b[!ship].front().first <= k) {
                k += t;
                ship = !ship;
                while (b[ship].front().first <= k && !b[ship].empty() && car < n) {
                    car++;
                    ans[b[ship].front().second] = k + t;
                    b[ship].pop();
                }
                ship = !ship;
                k += t;
            }
        }
        for (int i = 0; i < m; i++) {
            cout << ans[i] << endl;
        }
        if (u)
            cout << endl;
    }
}
