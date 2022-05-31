#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const vector<vector<vector<pair<int, int>>>> check = {
	{
		{ {0, 2} },
		{ },
		{ {0, 2}, {1, 1}, {1, 2} }
	},
	{
		{ },
		{ {2, 0} },
		{ {1, 1}, {2, 0}, {2, 1} }
	},
	{
		{ {1, 2} },
		{ {2, 1} },
		{ {1, 2}, {2, 1}, {2, 2} }
	}
};

const vector<pair<int, int>> offset = {
	{0, 1}, {1, 0}, {1, 1}
};

bool isValid(int r, int c, const vector<vector<int>>& board,
	const vector<pair<int, int>>& check_offset)
{
	if (check_offset.empty()) return false;

	for (const pair<int, int>& p : check_offset)
	{
		int nextR = r + p.first;
		int nextC = c + p.second;

		if (nextR < 0 || nextR >= board.size() 
			|| nextC < 0 || nextC >= board[0].size())
			return false;

		if (board[nextR][nextC] == 1)
			return false;
	}
	return true;
}

int BFS(const vector<vector<int>>& board)
{
	queue<tuple<int, int, int>> que;
	que.push({ 0,0,0 });

	int val = 0;
	while (que.empty() == false)
	{
		auto [r, c, way] = que.front();
		que.pop();

		int er = r + offset[way].first;
		int ec = c + offset[way].second;
		if (er == board.size()-1 && ec == board[0].size()-1)
		{
			val += 1;
			continue;
		}

		for (int i = 0; i < check[way].size(); i++)
		{
			if (isValid(r, c, board, check[way][i]))
			{
				que.push({ r + offset[way].first, c + offset[way].second, i });
			}
		}
	}
	return val;
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	cout << BFS(board) << endl;
}