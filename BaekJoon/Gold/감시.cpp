#include <iostream>
#include <vector>

using namespace std;

vector<vector<vector<pair<int,int>>>> dir =
{
	{ },
	{	
		{ {+1, 0} },
		{ {-1, 0} }, 
		{ {0, +1} }, 
		{ {0, -1} }
	},
	{ 
		{ {+1, 0}, {-1, 0} }, 
		{ {0, +1}, {0, -1} } 
	},
	{ 
		{ {+1, 0}, {0, +1} }, 
		{ {+1, 0}, {0, -1} }, 
		{ {-1, 0}, {0, +1} }, 
		{ {-1, 0}, {0, -1} } 
	},
	{	
		{ {+1, 0}, {0, +1}, {0, -1} }, 
		{ {-1, 0}, {0, +1}, {0, -1} },
		{ {0, +1}, {-1, 0}, {+1, 0} },
		{ {0, -1}, {-1, 0}, {+1, 0} },
	},
	{ 
		{ {+1, 0}, {-1, 0}, {0, +1}, {0, -1} }
	}
};

vector<vector<int>> room;
vector<pair<int, int>> cctv;

bool isValid(const pair<int, int>& p)
{
	return ((p.first < 0 || p.first > room.size() - 1
		|| p.second < 0 || p.second > room[0].size() - 1
		|| room[p.first][p.second] == 6) == false);
}

void mark(const pair<int,int>& pos, vector<vector<int>>& temp_room, const vector<pair<int, int>>& ways)
{
	for (const auto& p : ways)
	{
		auto temp_pos = pos;
		while (isValid(temp_pos))
		{
			temp_room[temp_pos.first][temp_pos.second] = 10;
			temp_pos.first += p.first;
			temp_pos.second += p.second;
		}
	}
}

int countSpaces(const vector<vector<int>>& temp_room)
{
	int count = 0;
	for (const auto& vec : temp_room)
	{
		for (int e : vec)
		{
			if (e == 0)
				count += 1;
		}
	}
	return count;
}

void getMinSpace(int& val, int idx, vector<vector<int>> temp_room)
{
	if (cctv.empty()) return;
	int way = room[cctv[idx].first][cctv[idx].second];

	for (const auto& ways : dir[way])
	{
		auto temp = temp_room;
		mark(cctv[idx], temp, ways);
		
		if(idx < cctv.size()-1)
			getMinSpace(val, idx + 1, temp);
		else
			val = min(countSpaces(temp), val);
	}
}

int solve()
{
	int min_value = countSpaces(room);
	getMinSpace(min_value, 0, room);
	return min_value;
} 

int main()
{
	int n, m;
	cin >> n >> m;

	room.resize(n, vector<int>(m, 0));	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> room[i][j];
			if (0 < room[i][j] && room[i][j] < 6)
				cctv.push_back({ i, j });
		}
	}
	cout << solve() << endl;
}