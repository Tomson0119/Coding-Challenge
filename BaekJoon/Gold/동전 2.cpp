#include <iostream>
#include <vector>

using namespace std;

int solve(const vector<int>& coin, int k)
{
	vector<int> dp(k + 1, -1);
	dp[0] = 0;

	for (int c : coin) {
		dp[c] = 1;

		for (int i = c; i <= k; i++) {
			if(dp[i-c] > 0) {
				dp[i] = (dp[i] > 0) ? min(dp[i], dp[i - c] + 1) : dp[i - c] + 1;
			}
		}
	}
	return dp[k];
}

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> coin(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	cout << solve(coin, k) << "\n";
}