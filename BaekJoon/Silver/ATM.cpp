#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> times(n);
	for (int i = 0; i < n; i++)
	{
		cin >> times[i];
	}
	
	sort(times.begin(), times.end());

	int accum = 0;
	int total = 0;
	for (int e : times)
	{
		accum += e;
		total += accum;
	}
	cout << total << "\n";
}