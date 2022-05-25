#include <iostream>
#include <vector>

using namespace std;

const int MODE = 1'000'000'007;

int solution(int m, int n, vector<vector<int>> puddles)
{
	vector<vector<int>> dp(n, vector<int>(m));
	for (const vector<int>& vec : puddles)
	{
		dp[vec[1] - 1][vec[0] - 1] = -1;
	}

	dp[0][0] = 1;
	for (int i = 0; i < dp.size(); i++)
	{
		for (int j = 0; j < dp[i].size(); j++)
		{
			if (dp[i][j] < 0) continue;

			if (i > 0 && dp[i - 1][j] >= 0)
            {
				dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MODE;
            }
			if (j > 0 && dp[i][j - 1] >= 0)
            {
				dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MODE;
            }
		}
	}

	return dp[n - 1][m - 1];
}

int main()
{
	cout << solution(4, 3, { {2,2} }) << endl; // 4
}