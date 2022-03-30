#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> tetrominos = {

	// ㅁㅁㅁㅁ
	{ {0, 0}, {0, 1}, {0, 2}, {0, 3} },

	// ㅁ
	// ㅁ
	// ㅁ
	// ㅁ
	{ {0, 0}, {1, 0}, {2, 0}, {3, 0} },

	// ㅁㅁ
	// ㅁㅁ
	{ {0, 0}, {0, 1}, {1, 0}, {1, 1} },

	// ㅁ
	// ㅁ
	// ㅁㅁ
	{ {0, 0}, {1, 0}, {2, 0}, {2, 1} },

	//     ㅁ
	// ㅁㅁㅁ
	{ {0, 0}, {0, 1}, {0, 2}, {-1, 2} },

	// ㅁㅁ
	//   ㅁ
	//   ㅁ
	{ {0, 0}, {0, 1}, {1, 1}, {2, 1} },

	// ㅁㅁㅁ
	// ㅁ
	{ {0, 0}, {0, 1}, {0, 2}, {1, 0} },

	//   ㅁ 
	//   ㅁ
	// ㅁㅁ
	{ {0, 0}, {1, 0}, {2, 0}, {2, -1} },

	// ㅁㅁㅁ
	//     ㅁ
	{ {0, 0}, {0, 1}, {0, 2}, {1, 2} },

	// ㅁㅁ
	// ㅁ
	// ㅁ
	{ {0, 0}, {0, 1}, {1, 0}, {2, 0} },

	// ㅁ
	// ㅁㅁㅁ
	{ {0, 0}, {1, 0}, {1, 1}, {1, 2} },

	// ㅁ
	// ㅁㅁ
	//   ㅁ
	{ {0, 0}, {1, 0}, {1, 1}, {2, 1} },

	//   ㅁㅁ
	// ㅁㅁ
	{ {0, 0}, {0, 1}, {-1, 1}, {-1, 2} },

	//   ㅁ
	// ㅁㅁ
	// ㅁ
	{ {0, 0}, {1, 0}, {1, -1}, {2, -1} },

	// ㅁㅁ
	//   ㅁㅁ
	{ {0, 0}, {0, 1}, {1, 1}, {1, 2} },

	// ㅁㅁㅁ
	//   ㅁ
	{ {0, 0}, {0, 1}, {0, 2}, {1, 1} },

	// ㅁ
	// ㅁㅁ
	// ㅁ
	{ {0, 0}, {1, 0}, {2, 0}, {1, 1} },

	//   ㅁ
	// ㅁㅁㅁ
	{ {0, 0}, {0, 1}, {0, 2}, {-1, 1} },

	//   ㅁ
	// ㅁㅁ
	//   ㅁ 
	{ {0, 0}, {1, 0}, {2, 0}, {1, -1} }
};

bool checkBoundary(int r, int c, const vector<vector<int>>& board)
{
	if (r < 0 || r >= board.size()) return false;
	if (c < 0 || c >= board[0].size()) return false;
	return true;
}

int getTotalValue(int r, int c, const vector<vector<int>>& board)
{
	int max_val = -1;
	for (const vector<pair<int, int>>& tetromino : tetrominos)
	{
		int value = 0;
		for (const pair<int, int>& p : tetromino)
		{
			if (checkBoundary(r + p.first, c + p.second, board) == false)
			{
				value = -1;
				break;
			}
			value += board[r + p.first][c + p.second];
		}
		max_val = (max_val < value) ? value : max_val;
	}
	return max_val;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	int max_val = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int val = getTotalValue(i, j, board);
			max_val = (max_val < val) ? val : max_val;
		}
	}
	cout << max_val << "\n";
}