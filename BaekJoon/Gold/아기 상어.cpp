#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int MAX_DIST = 401;

vector<pair<int, int>> delta = {
	{-1, 0}, {0, -1}, {1, 0}, {0, 1}
};

bool checkIfValid(
	int r, int c, int w, int len, 
	vector<vector<bool>>& visited, 
	const vector<vector<int>>& board)
{
	if (r < 0 || r >= len ||
		c < 0 || c >= len ||
		board[r][c] > w ||
		visited[r][c] == true)
		return false;

	visited[r][c] = true;
	return true;
}

bool isSmallerFish(int r, int c, int w, const vector<vector<int>>& board)
{
	return (board[r][c] != 0 && board[r][c] < w);
}

int setShortestDist(
	int dist, int min_dist, 
	pair<int, int>& last, 
	const pair<int, int>& current)
{
	if (dist < min_dist)
	{
		last = current;
		return dist;
	}
	if (dist == min_dist)
	{
		if (last.first > current.first)
		{
			last = current;
		}
		else if (current.first == last.first)
		{
			if (current.second < last.second)
			{
				last = current;
			}
		}
	}
	return min_dist;
}

int getDistance(pair<int, int>& shark, vector<vector<int>>& board, int w)
{	
	queue<tuple<int, int, int>> que;
	que.push({ shark.first, shark.second, 0 });

	vector<vector<bool>> visited(board.size(), vector<bool>(board.size(), false));
	visited[shark.first][shark.second] = true;
	board[shark.first][shark.second] = 0;

	pair<int, int> last = { -1, -1 };
	int min_dist = MAX_DIST;
	while (que.empty() == false)
	{
		int r = get<0>(que.front());
		int c = get<1>(que.front());
		int dist = get<2>(que.front());
		que.pop();

		for (const pair<int, int>& p : delta)
		{
			if (checkIfValid(r+p.first, c+p.second, w, board.size(), visited, board))
			{
				if (isSmallerFish(r + p.first, c + p.second, w, board))
				{
					min_dist = setShortestDist(dist + 1, min_dist, last, { r + p.first, c + p.second });
					continue;
				}
				que.push({ r + p.first, c + p.second, dist + 1 });
			}
		}
	}
	if (last.first >= 0 && last.second >= 0)
	{
		shark = last;
	}
	return min_dist;
}

int solve(pair<int, int>& shark, vector<vector<int>>& board)
{
	int weight = 2;
	int time = 0;
	int cnt = weight;
	while (true)
	{
		int val = getDistance(shark, board, weight);
		if (val >= MAX_DIST) break;

		time += val;
		cnt -= 1;
		if (cnt == 0)
		{
			weight += 1;
			cnt = weight;
		}
	}
	return time;
}

int main()
{
	int n;
	cin >> n;

	pair<int, int> shark;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n * n; i++)
	{
		int r = i / n;
		int c = i % n;
		cin >> board[r][c];

		if (board[r][c] == 9)
		{
			shark = { r,c };
		}
	}

	cout << solve(shark, board) << "\n";
}