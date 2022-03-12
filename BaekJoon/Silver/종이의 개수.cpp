#include <iostream>
#include <vector>

using namespace std;

void print(const vector<vector<int>>& paper)
{
	for (const vector<int>& vec : paper)
	{
		for (int e : vec)
		{
			if (e >= 0) cout << " ";
			cout << e << " ";
		}
		cout << "\n";
	}
}

int getValueIfAllSame(int row, int col, int len, const vector<vector<int>>& paper)
{
	int val = paper[row][col];
	for (int i = row; i < row + len; i++)
	{
		for (int j = col; j < col + len; j++)
		{
			if (val != paper[i][j]) return -2;
		}
	}
	return val;
}

void Search(int row, int col, int len,
	const vector<vector<int>>& paper, int counts[])
{
	int val = getValueIfAllSame(row, col, len, paper);
	if (val >= -1)
	{
		counts[val + 1] += 1;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int increase = len / 3;
			Search(row + increase * i, col + increase * j, increase, paper, counts);
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<int>> paper(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> paper[i][j];
		}
	}

	int counts[3] = { 0, 0, 0 };

	Search(0, 0, n, paper, counts);

	for (int i = 0; i < 3; i++)
		cout << counts[i] << "\n";
}