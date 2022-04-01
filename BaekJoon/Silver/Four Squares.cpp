#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int INF = 987654321;

int main()
{
	int n;
	cin >> n;

	vector<int> dp(n+1, INF);
	for (int i = 1; i <= n; i++)
	{
		int srt = sqrt(i);
		if (srt * srt == i)
			dp[i] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int k = 0; k * k <= i; k++)
		{
			dp[i] = min(dp[i], dp[i - k * k] + 1);
		}
	}
	cout << dp[n] << "\n";
}