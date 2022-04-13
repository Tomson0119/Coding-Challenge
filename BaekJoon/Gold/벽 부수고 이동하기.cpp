#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

vector<pair<int, int>> dm = {
	{-1,0}, {1, 0}, {0,-1}, {0,1}
};

int BFS(const vector<string>& board)
{
	queue<tuple<int, int, int, bool>> que;
	que.push({ 0,0,1,false });

	vector<vector<bool>> visited1(board.size(), vector<bool>(board[0].size(),false));
	vector<vector<bool>> visited2(board.size(), vector<bool>(board[0].size(),false));
	while (que.empty() == false)
	{
		auto [r, c, dist, broken] = que.front();
		que.pop();

		if (r == board.size() - 1 && c == board[0].size() - 1)
			return dist;

		for (const pair<int, int>& p : dm)
		{
			int nr = r + p.first;
			int nc = c + p.second;
			if (nr < 0 || nr >= board.size() 
				|| nc < 0 || nc >= board[0].size())
			{
				continue;
			}

			if (broken == false && board[nr][nc] == '1' && visited2[nr][nc] == false)
			{
				visited2[nr][nc] = true;
				que.push({ nr,nc,dist + 1,true });
			}
			else if(board[nr][nc] == '0')
			{
				if (broken && visited1[nr][nc] == false)
				{
					visited1[nr][nc] = true;
					que.push({ nr,nc,dist + 1,broken });
				}
				else if (broken == false && visited2[nr][nc] == false)
				{
					visited2[nr][nc] = true;
					que.push({ nr,nc,dist + 1,broken });
				}
			}
		}
	}
	return -1;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<string> board(n);
	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	cout << BFS(board) << "\n";
}