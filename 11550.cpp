#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a, b;
	cin >> n;
	while (n--)
	{
		cin >> a >> b;
		vector<int> arr[300];
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				int v;
				cin >> v;
				arr[j].push_back(v);
			}
		}

		bool aa = false;
		for (int i = 0; i < b; i++)
			for (int j = i + 1; j < b; j++)
				if (arr[j] == arr[i]) aa = true;
		for (int i = 0; i < b && !aa; i++)
		{
			int ans = 0;
			for (int j = 0; j < a && !aa; j++)
				if (arr[i][j])
					ans += arr[i][j];
			aa = !(ans == 2);
		}

		if (!aa) cout << "Yes\n";
		else cout << "No\n";
	}
}
