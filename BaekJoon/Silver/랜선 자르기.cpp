#include <iostream>

using namespace std;
using llong = long long;

llong line[10000];

int GetSum(int k, llong v)
{
	int sum = 0l;
	for (int i = 0; i < k; i++)
	{
		sum += (line[i] / v);
	}
	return sum;
}

int Search(llong start, llong end, int k, int n)
{
	int answer = -1;
	while (start <= end)
	{
		llong mid = (start + end) / 2;
		if (mid == 0) mid = 1;

		if (GetSum(k, mid) >= n)
		{
			if (mid > answer)
				answer = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	return answer;
}

int main()
{
	int k, n;
	cin >> k >> n;

	llong minv = 4294967296, maxv = -1;
	for (int i = 0; i < k; i++)
	{
		cin >> line[i];
		minv = min(minv, line[i]);
		maxv = max(maxv, line[i]);
	}
	llong start = minv / (n / k + 1);
	llong end = maxv;
	cout << Search(start, end, k, n) << "\n";
}