#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1'000'000'000;

int main()
{
	int n;
	cin >> n;

	int k;
	cin >> k;

	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 2; j <= k; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}
	cout << dp[n][k] % MOD << "\n";
}