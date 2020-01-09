#include <bits/stdc++.h>
#define ms(x, a) memset(x, a, sizeof(x))
#define INF 1000000
using namespace std;
int n;
string s;
int dp[1 << 13];
int setbit(int a, int i, int x)
{
    if (x == 1) {
        int y = x << i;
        return a | y;
    }
    else {
        int y = 1 << i;
        return (~y) & a;
    }
}
int cntbit(int a)
{
    int ans = 0;
    while (a) {
        ans += (a & 1);
        a = a >> 1;
    }
    return ans;
}
bool stat(int boolin, int i)
{
    return ((1 << i) & boolin) != 0;
}
bool twoadj(int b)
{
    int last = 0;
    while (b) {
        if (last && (b & 1))
            return true;
        last = b & 1;
        b >>= 1;
    }
    return false;
}
int cnt(int boolin)
{
    if (dp[boolin] + 1)
        return dp[boolin];
    if (!twoadj(boolin)) {
        return dp[boolin] = cntbit(boolin);
    }
    int ans = INF;
    if (stat(boolin, 0) == 1 && stat(boolin, 1) == 1) {
        if (stat(boolin, 2) == 0) {
            int temp = setbit(boolin, 0, 0);
            temp = setbit(temp, 1, 0);
            temp = setbit(temp, 2, 1);
            ans = min(ans, cnt(temp));
        }
    }
    for (int i = 1; i < 10; i++) {
        if (stat(boolin, i) == 1 && stat(boolin, i + 1) == 1) {
            if (stat(boolin, i - 1) == 0) {
                int temp = setbit(boolin, i + 1, 0);
                temp = setbit(temp, i, 0);
                temp = setbit(temp, i - 1, 1);
                ans = min(ans, cnt(temp));
            }
            if (stat(boolin, i + 2) == 0) {
                int temp = setbit(boolin, i + 1, 0);
                temp = setbit(temp, i, 0);
                temp = setbit(temp, i + 2, 1);
                ans = min(ans, cnt(temp));
            }
        }
    }
    if (stat(boolin, 10) == 1 && stat(boolin, 11) == 1) {
        if (stat(boolin, 9) == 0) {
            int temp = setbit(boolin, 10, 0);
            temp = setbit(temp, 11, 0);
            temp = setbit(temp, 9, 1);
            ans = min(ans, cnt(temp));
        }
    }
    return dp[boolin] = ans;
}
int st(string s)
{
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-')
            ans = (ans << 1);
        else
            ans = (ans << 1) + 1;
    }
    return ans;
}
int main()
{
    cin >> n;
    while (n--) {
        ms(dp, -1);
        cin >> s;
        if (cnt(st(s)) != INF) {
            cout << cnt(st(s)) << endl;
        }
        else
            cout << cntbit(st(s)) << endl;
    }

    return 0;
}
