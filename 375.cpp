
#include <bits/stdc++.h>
#define INF 102222222
#define ll unsigned long long int
using namespace std;
void printspace(ll x, int y)
{
    int k = 1;
    while (k < y) {
        if (x < pow(10, k)) {
            for (int i = 0; i < y - (k + 3); i++)
                cout << " ";
            return;
        }
        k++;
    }
}
int main()
{
    int coins[5] = { 1, 5, 10, 25, 50 };
    ll ways[4000000];
    memset(ways, 0, sizeof(ways));
    ways[0] = 1;
    for (int i = 0; i < 5; i++) {
        for (ll j = coins[i]; j <= 300000; j++) {
            ways[j] = ways[j - coins[i]] + ways[j];
        }
    }
    int a;
    cin >> a;
    while (!cin.fail()) {
        int y = a;
        if (ways[y] > 1)
            printf("There are %lld ways to produce %d cents change.\n", ways[y], a);
        else
            printf("There is only 1 way to produce %d cents change.\n", a);
        cin >> a;
    }
}
