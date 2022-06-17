#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> matrix(n, vector<int>(n));
	vector<vector<int>> sums(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
			sums[i][j] = matrix[i][j];
			
			if (i > 0)
				sums[i][j] += sums[i - 1][j];
			if (j > 0)
				sums[i][j] += sums[i][j - 1];
			if (i > 0 && j > 0)
				sums[i][j] -= sums[i - 1][j - 1];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		int sum = sums[x2-1][y2-1];
		if (x1 > 1)
			sum -= sums[x1 - 2][y2-1];
		if (y1 > 1)
			sum -= sums[x2-1][y1 - 2];
		if(x1 > 1 && y1 > 1)
			sum += sums[x1 - 2][y1 - 2];

		cout << sum << "\n";
	}
}