#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long BinarySearch(int n, vector<int>& times, long long left, long long right)
{
	long long answer = right;
	while (left <= right)
	{
		long long mid = (left + right) / 2;

		long long total = 0;
		for (int time : times)
		{
			total += mid / time;
			if (total >= n) break;
		}

		if (total >= n)
		{
			if(answer > mid) answer = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return answer;
}

long long solution(int n, vector<int> times)
{
	sort(times.begin(), times.end());

	long long min_v = (long long)times.front();
	long long max_v = (long long)times.back() * n;

	return BinarySearch(n, times, min_v, max_v);
}

int main()
{
	cout << solution(6, { 7,10 }) << endl;
}