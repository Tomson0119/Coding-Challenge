#include <iostream>
#include <vector>

using namespace std;

const vector<pair<int, int>> offset = {
	{-1, 0}, {0, 1}, {0, -1}, {1, 0}
};

const vector<vector<pair<int, int>>> wind_offset = {
	{ {0, -1}, {-1, 0}, {0, 1}, {1, 0}, {0, -1} },
	{ {0, -1}, {1, 0}, {0, 1}, {-1, 0}, {0, -1} }
};

bool isValid(const pair<int, int>& p, const pair<int,int>& curr, const vector<vector<int>>& room)
{
	int nextR = curr.first + p.first;
	int nextC = curr.second + p.second;

	if (nextR < 0 || nextR >= room.size() || nextC < 0 || nextC >= room[0].size())
		return false;

	return (room[nextR][nextC] != -1);
}

void spreadDust(vector<vector<int>>& room)
{
	vector<vector<int>> newDust(room.size(), vector<int>(room[0].size(), 0));
	for (int i = 0; i < room.size(); i++)
	{
		for (int j = 0; j < room[0].size(); j++)
		{
			if (room[i][j] < 0) continue;

			int amount = room[i][j] / 5;
			int count = 0;
			for (const pair<int, int>& p : offset)
			{
				if (isValid(p, { i, j }, room))
				{
					newDust[i + p.first][j + p.second] += amount;
					count += 1;
				}
			}
			room[i][j] -= amount * count;
		}
	}
	for (int i = 0; i < room.size(); i++)
	{
		for (int j = 0; j < room[0].size(); j++)
		{
			room[i][j] += newDust[i][j];
		}
	}
}

void activateCleaner(const vector<pair<int, int>>& cleaner, vector<vector<int>>& room)
{
	for (int k = 0; k < cleaner.size(); k++)
	{
		auto current = cleaner[k];
		for (const pair<int,int>& p : wind_offset[k])
		{
			while (isValid(p, current, room))
			{
				if (k == 0 && current.first + p.first > cleaner[k].first)
					break;
				if (k == 1 && current.first + p.first < cleaner[k].first)
					break;
				
				int nextR = current.first + p.first;
				int nextC = current.second + p.second;

				if (room[current.first][current.second] == 0)
				{
					room[current.first][current.second] = room[nextR][nextC];
				}

				room[nextR][nextC] = 0;

				current.first += p.first;
				current.second += p.second;
			}
		}
	}
}

void simulate(const vector<pair<int, int>>& cleaner, vector<vector<int>>& room)
{
	spreadDust(room);
	activateCleaner(cleaner, room);
}

int getTotalDust(const vector<vector<int>>& room)
{
	int total = 0;
	for (const vector<int>& row : room)
	{
		for (int e : row)
		{
			if (e > 0)
				total += e;
		}
	}
	return total;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int r, c, t;
	cin >> r >> c >> t;
	
	vector<pair<int, int>> cleaner;
	vector<vector<int>> room(r, vector<int>(c));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int val;
			cin >> val;
			room[i][j] = val;

			if (val == -1)
				cleaner.push_back({ i,j });
		}
	}

	for (int i = 0; i < t; i++)
	{
		simulate(cleaner, room);
	}

	cout << getTotalDust(room) << "\n";
}