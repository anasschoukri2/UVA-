#include <bits/stdc++.h>
#define INF 102222222
#define ll long long int
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
    int coins[11] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };
    ll ways[40000];
    memset(ways, 0, sizeof(ways));
    ways[0] = 1;
    for (int i = 0; i < 11; i++) {
        for (int j = coins[i]; j <= 30000; j++) {
            ways[j] = ways[j - coins[i]] + ways[j];
        }
    }
    double a;
    cin >> a;
    while (a != 0) {
        printspace(floor(a), 6);
        int y = a * 10000;
        y /= 100;
        printf("%0.2f", a);
        printspace(ways[y], 20);
        cout << ways[y] << endl;
        cin >> a;
    }
}
