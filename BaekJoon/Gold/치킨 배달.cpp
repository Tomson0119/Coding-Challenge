#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int getDistance(const pair<int,int>& a, const pair<int,int>& b)
{
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int getMinDist(const vector<int>& picks, const vector<vector<int>>& distance)
{
	int dist = 0;
	for (const vector<int>& vec : distance)
	{
		int val = -1;
		for (int e : picks)
		{
			if (val < 0 || val > vec[e])
			{
				val = vec[e];
			}
		}
		dist += val;
	}
	return dist;
}

void backTracking(int& min_val, const vector<vector<int>>& distance,
	vector<int> picks, int idx, int n, int m)
{
	if (picks.size() == m)
	{
		int val = getMinDist(picks, distance);
		if (min_val < 0 || min_val > val)
		{
			min_val = val;
		}
		return;
	}

	for (int i = idx; i < n; i++)
	{
		vector<int> copy_picks = picks;
		copy_picks.push_back(i);
		backTracking(min_val, distance, copy_picks, i+1, n, m);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> houses;
	vector<pair<int, int>> stores;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int val;
			cin >> val;

			if (val == 1)
				houses.push_back({ i + 1,j + 1 });
			else if (val == 2)
				stores.push_back({ i + 1,j + 1 });
		}
	}

	vector<vector<int>> distance(houses.size(), vector<int>(stores.size()));
	for (int i=0;i<houses.size();i++)
	{
		for (int j=0;j<stores.size();j++)
		{
			distance[i][j] = getDistance(houses[i], stores[j]);
		}
	}

	int min_val = -1;
	vector<int> picks;
	backTracking(min_val, distance, picks, 0, stores.size(), m);

	cout << min_val << "\n";
}