#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int prev_min[3], prev_max[3];
	cin >> prev_min[0] >> prev_min[1] >> prev_min[2];
	prev_max[0] = prev_min[0], prev_max[1] = prev_min[1], prev_max[2] = prev_min[2];
	
	for (int i = 1; i < n; i++)
	{
		int currn[3];
		cin >> currn[0] >> currn[1] >> currn[2];
		
		int curr_min[3] = { 987654321,987654321,987654321 };
		int curr_max[3] = { -1, -1, -1 };

		for (int j = 0; j < 3; j++)
		{
			if (j > 0)
			{
				curr_min[j] = min(curr_min[j], currn[j] + prev_min[j - 1]);
				curr_max[j] = max(curr_max[j], currn[j] + prev_max[j - 1]);
			}

			curr_min[j] = min(curr_min[j], currn[j] + prev_min[j]);
			curr_max[j] = max(curr_max[j], currn[j] + prev_max[j]);

			if (j < 2)
			{
				curr_min[j] = min(curr_min[j], currn[j] + prev_min[j + 1]);
				curr_max[j] = max(curr_max[j], currn[j] + prev_max[j + 1]);
			}
		}

		for (int j = 0; j < 3; j++)
		{
			prev_min[j] = curr_min[j];
			prev_max[j] = curr_max[j];
		}
	}

	cout << *max_element(begin(prev_max), end(prev_max)) << " "
		<< *min_element(begin(prev_min), end(prev_min)) << "\n";
}