#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
using namespace std;
string s;
int pre[1000005];
void pr()
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
    while (cin >> s && s != ".") {
        ms(pre, 0);
        pr();
        cout << s.size() / (s.size() - pre[s.size() - 1]) << endl;
    }
}
