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
	sett[b] = a;
}
int main()
{
	int n, a, b;
	cin >> n;
	while (n--)
	{
		memset(sett, -1, sizeof(sett));
		int p, t;
		cin >> p >> t;
		string u;
		cin.ignore();
		vector<int> opin[330];
		while (getline(cin, u))
		{
			int a = 0, b = 0;
			int i = 0;
			for (i = 0; u[i] != ' '; i++)
				a = a *10 + (u[i] - '0');
			i++;
			for (; i < u.size(); i++)
				b = b *10 + (u[i] - '0');
			opin[a].push_back(b);
			sett[a] = a;
		}
		for (int i = 1; i <= p; i++)
			for (int j = 1; j <= p; j++)
				if (opin[i] == opin[j])
					join(a, b);
		int ans = 0;
		for (int i = 1; i <= p; i++)
			if (sett[i] == i)
				ans++;
		cout << ans << endl;
	}
}
