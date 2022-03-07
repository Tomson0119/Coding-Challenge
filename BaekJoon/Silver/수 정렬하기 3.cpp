#include <iostream>

using namespace std;

int cnt[10'001];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;

		cnt[v] += 1;
	}

	for (int i = 1; i < 10'001; i++)
	{
		if (cnt[i] > 0)
		{
			for (int k = 0; k < cnt[i]; k++)
				cout << i << "\n";
		}
	}
}