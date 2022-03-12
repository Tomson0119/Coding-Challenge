#include <iostream>
#include <vector>
#include <string>

using namespace std;

char getSameValue(int row, int col, int len, const vector<string>& arr)
{
	char val = arr[row][col];
	for (int i = row; i < row + len; i++)
	{
		for (int j = col; j < col + len; j++)
		{
			if (val != arr[i][j]) return -1;
		}
	}
	return val;
}

void QuadTree(int row, int col, int len, const vector<string>& arr, string& s)
{
	char val = getSameValue(row, col, len, arr);
	if (val < 0)
	{
		len /= 2;

		s += "(";
		QuadTree(row, col, len, arr, s);
		QuadTree(row, col + len, len, arr, s);
		QuadTree(row+len, col, len, arr, s);
		QuadTree(row+len, col + len, len, arr, s);
		s += ")";
	}
	else
	{
		s += val;
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<string> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	string s = "";
	QuadTree(0, 0, n, arr, s);

	cout << s << "\n";
}