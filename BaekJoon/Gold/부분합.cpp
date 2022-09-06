#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, s;
	cin >> n >> s;

	vector<long long> sums(n, 0);
	int prev_idx = 0;
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;

		sums[i] = (i == 0) ? val : sums[i - 1] + val;
		if (sums[i] < s) continue;
		
		for (int k = prev_idx; k <= i; k++)
		{
			long long diff = sums[i] - sums[k];
			if (diff < s)
			{
				prev_idx = (k > 0) ? k - 1 : 0;
				int len = i - k + 1;
				if (answer == 0 || answer > len)
				{
					answer = len;
				}
				break;
			}
		}
	}
	cout << answer << "\n";
}