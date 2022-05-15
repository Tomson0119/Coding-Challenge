#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
	cin >> t;

	while (t--)
	{
		int col;
		cin >> col;

		vector<vector<int>> stickers(2, vector<int>(col));
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cin >> stickers[i][j];
			}
		}

		vector<vector<int>> dp(2, vector<int>(col));
		dp[0][0] = stickers[0][0];
		dp[1][0] = stickers[1][0];

		if (col > 1)
		{
			dp[0][1] = dp[1][0] + stickers[0][1];
			dp[1][1] = dp[0][0] + stickers[1][1];
		}
		
		for (int i = 2; i < col; i++)
		{
			dp[0][i] = max(dp[1][i - 2], dp[1][i - 1]) + stickers[0][i];
			dp[1][i] = max(dp[0][i - 2], dp[0][i - 1]) + stickers[1][i];
		}

		cout << max(dp[0].back(), dp[1].back()) << "\n";
	}
}