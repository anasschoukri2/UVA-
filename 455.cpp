#include <bits/stdc++.h>
using namespace std;
int pre[100];
string s;
void pp()
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
    int N;
    cin >> N;
    while (N--) {
        memset(pre, 0, sizeof(pre));
        cin >> s;
        int i = s.size();
        pp();
        pre[i] = pre[i - 1] + 1;
        while (pre[i - 1] && pre[i] == pre[i - 1] + 1 && i)
            i--;
        if (!((s.size()) % i))
            cout << i << endl;
        else
            cout << s.size() << endl;
        if (N)
            cout << endl;
    }
}
