#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T = 0;
    string ss;
    while (cin >> ss && ss != "end") {
        T++;
        stack<char> s[1000];
        char used[26];
        memset(used, 0, sizeof(used));
        int k = 0, l = 0;
        for (int i = 0; i < ss.size(); i++) {
            used[tolower(ss[i]) - 'a']++;
            bool add = 0;
            for (int j = 1; j <= k; j++) {
                if (s[j].top() >= ss[i]) {
                    s[j].push(ss[i]);
                    add = 1;
                    break;
                }
            }
            if (!add) {
                k++;
                s[k].push(ss[i]);
            }
        }
        cout << "Case " << T << ": " << k << endl;
    }
}
