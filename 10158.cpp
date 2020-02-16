#include <bits/stdc++.h>
using namespace std;
int sett[40005];
int findd(int a)
{
	if (a == sett[a]) return a;
	return sett[a] = findd(sett[a]);
}

void join(int a, int b)
{
	a = findd(a);
	b = findd(b);
	if (a == b) return;
	sett[a] = b;
}

int main()
{
	int n, q, a, b;
	cin >> n;
	for (int i = 0; i <= 3 * n; i++) sett[i] = i;
	while (cin >> q >> a >> b && q)
		if (q == 1)
		{
			if (findd(a) == findd(b + n + 1) || findd(b) == findd(a + n + 1))
			{
				cout << -1 << endl;
				continue;
			}
			join(a, b);
			join(a + n + 1, b + n + 1);
		}
	else if (q == 2)
	{
		if (findd(a + n + 1) == findd(b + n + 1) || findd(b) == findd(a))
		{
			cout << -1 << endl;
			continue;
		}
		join(a, b + n + 1);
		join(b, a + n + 1);
	}
	else if (q == 3)
		cout << ((findd(a) == findd(b)) || (findd(a + n + 1) == findd(b + n + 1))) << endl;
	else
		cout << ((findd(a) == findd(b + n + 1)) || (findd(a + n + 1) == findd(b))) << endl;
}
