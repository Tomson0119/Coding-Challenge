#include <iostream>
#include <vector>

using namespace std;
using ullong = unsigned long long;

ullong solve(const vector<vector<int>>& board)
{
	vector<vector<ullong>> dp(board.size(), vector<ullong>(board[0].size(), 0));
	dp[0][0] = 1;
	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[0].size(); j++) {
			if (board[i][j] == 0) continue;

			int down = i + board[i][j];
			int right = j + board[i][j];
			if (down < dp.size()) {
				dp[down][j] += dp[i][j];
			}
			if (right < dp.size()) {
				dp[i][right] += dp[i][j];
			}
		}
	}
	return dp.back().back();
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> board(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	cout << solve(board) << "\n";
}