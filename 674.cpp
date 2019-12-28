#include <bits/stdc++.h>
using namespace std;
int a, ways[40000], coins[5] = { 50, 25, 10, 5, 1 };
int main()
{
    ways[0] = 1;
    for (int i = 0; i < 5; i++)
        for (int j = coins[i]; j <= 7500; j++)
            ways[j] = ways[j - coins[i]] + ways[j];
    cin >> a;
    while (!cin.fail()) {
        cout << ways[a] << "\n";
        cin >> a;
    }
}
