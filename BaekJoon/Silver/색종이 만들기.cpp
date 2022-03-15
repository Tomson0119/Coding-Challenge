#include <iostream>
#include <vector>

using namespace std;

int GetSameValue(int row, int col, int len, const vector<vector<int>>& paper)
{
	int val = paper[row][col];
	for (int i = row; i < row + len; i++)
	{
		for (int j = col; j < col + len; j++)
		{
			if (val != paper[i][j]) return -1;
		}
	}
	return val;
}

void Search(int row, int col, int len, const vector<vector<int>>& paper, int& blue, int& white)
{
	int res = GetSameValue(row, col, len, paper);
	if (res < 0)
	{
		int next_len = len / 2;
		Search(row, col, next_len, paper, blue, white);
		Search(row + next_len, col, next_len, paper, blue, white);
		Search(row, col + next_len, next_len, paper, blue, white);
		Search(row + next_len, col + next_len, next_len, paper, blue, white);
	}
	else
	{
		if (res == 1) blue += 1;
		else white += 1;
	}
}

int main()
{
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

	int blue = 0;
	int white = 0;
	Search(0, 0, n, paper, blue, white);

	cout << white << "\n";
	cout << blue << "\n";
}