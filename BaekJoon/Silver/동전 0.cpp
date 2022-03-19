#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> coins(n);
	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
	}

	int cnt = 0;
	for (int i = coins.size() - 1; i >= 0; i--)
	{
		if (k == 0) break;
		while (coins[i] <= k)
		{
			cnt += 1;
			k -= coins[i];
		}
	}
	cout << cnt << "\n";
}