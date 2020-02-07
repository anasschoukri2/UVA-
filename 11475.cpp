#include <bits/stdc++.h>
using namespace std;
int pre[1000045];
void pr(string s)
{
    for (int i = 0, j = 1; j < s.size(); j++) {
        while (s[i] != s[j] && i)
            i = pre[i - 1];
        if (s[i] == s[j])
            i++;
        pre[j] = i;
    }
}
int main()
{

    string s, a;
    while (cin >> s) {
        memset(pre, 0, sizeof(pre));
        a = s;
        reverse(a.begin(), a.end());
        pr(a);
        int maxi = 0;
        for (int i = 0, j = 0; j < s.size(); j++) {
            while (s[j] != a[i] && i)
                i = pre[i - 1];
            if (a[i] == s[j])
                i++;
            if (j == s.size() - 1)
                maxi = max(maxi, i);
        }
        int x = s.size() - maxi;
        cout << s;
        while (x--) {
            cout << s[x];
        }
        cout << endl;
    }
    return 0;
}
