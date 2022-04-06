#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> times(n);
	for (int i = 0; i < n; i++)
	{
		int t, s;
		cin >> t >> s;
		times[i] = { t,s };
	}

	sort(times.begin(), times.end(),
		[](const pair<int, int>& a, const pair<int, int>& b)
		{
			return (a.second > b.second);
		});

	vector<int> startTimes(n, -1);
	startTimes[0] = times[0].second - times[0].first;

	for (int i=1;i<times.size();i++)
	{
		pair<int, int>& p = times[i];

		if (startTimes[i - 1] < p.second)
			startTimes[i] = startTimes[i-1] - p.first;
		else
			startTimes[i] = p.second - p.first;
	}

	int answer = (startTimes.back() >= 0) ? startTimes.back() : -1;
	cout << answer << "\n";
}