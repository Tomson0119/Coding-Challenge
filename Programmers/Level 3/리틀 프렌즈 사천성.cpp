#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <algorithm>
#include <thread>

using namespace std;

bool check(int r, int c, char tile, const vector<string>& board)
{
	if (r < 0 || r > board.size() - 1
		|| c < 0 || c > board[0].size() - 1
		|| (board[r][c] != tile && board[r][c] != '.'))
		return false;
	return true;
}

pair<int,int> BFS(int x, int y, const vector<string>& board)
{
	// row, col, dir_row, dir_col, curved
	queue<tuple<int, int, int, int, bool>> que;
	que.push({ x,y, -1, 0, false });
	que.push({ x,y, +1, 0, false });
	que.push({ x,y, 0, -1, false });
	que.push({ x,y, 0, +1, false });

	char target = board[x][y];
	while (que.empty() == false)
	{
		auto [row, col, dr, dc, curved] = que.front();
		que.pop();

		if ((row != x || col != y) && board[row][col] == target)
		{
			return { row, col };
		}

		if (check(row + dr, col + dc, target, board))
			que.push({ row + dr, col + dc, dr, dc, curved });
		
		if ((row == x && col == y) || curved) continue;

		if (dc == 0)
		{
			if (check(row, col - 1, target, board))
				que.push({ row, col - 1, 0, -1, true });			
			if (check(row, col + 1, target, board))
				que.push({ row, col + 1,0,+1,true });
		}

		if (dr == 0)
		{
			if (check(row - 1, col, target, board))
				que.push({ row - 1,col,-1,0,true });
			if (check(row + 1, col, target, board))
				que.push({ row + 1,col,+1,0,true });
		}
	}
	return { -1,-1 };
}

char removeTile(int m, int n, vector<string>& board)
{
	char prevTile = -1;
	pair<int, int> point1;
	pair<int, int> point2;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '.' || board[i][j] == '*')
				continue;

			auto p = BFS(i, j, board);
			if (p.first < 0 || p.second < 0) 
				continue;

			if (prevTile < 0 || prevTile > board[i][j])
			{
				prevTile = board[i][j];
				point1 = { i,j };
				point2 = p;
			}
		}
	}

	board[point1.first][point1.second] = '.';
	board[point2.first][point2.second] = '.';

	return prevTile;
}

bool allClear(const vector<string>& board)
{
	for (const string& s : board)
	{
		for (char c : s)
		{
			if (c != '.' && c != '*')
			{
				return false;
			}
		}
	}
	return true;
}

string solution(int m, int n, vector<string> board)
{
	string answer;
	while (true)
	{
		char result = removeTile(m, n, board);
		if (result < 0)
		{
			if (allClear(board) == false)
			{
				answer = "IMPOSSIBLE";
			}
			break;
		}
        answer += result;
	}
	return answer;
}

int main()
{
	cout << solution(3, 3, { "DBA", "C*A", "CDB" }) << endl;
	cout << solution(2, 4, { "NRYN", "ARYA" }) << endl;
	cout << solution(4, 4, { ".ZI.", "M.**", "MZU.", ".IU." }) << endl;
	cout << solution(2, 2, { "AB", "BA" }) << endl;
}