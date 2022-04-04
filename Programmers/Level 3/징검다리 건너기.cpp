#include <vector>
#include <algorithm>

using namespace std;

bool crossable(const vector<int>& stones, int k, int n)
{
	int cnt = 0;
	for (int e : stones)
	{
		if (e < n)
		{
			cnt += 1;
		}
		else
		{
			cnt = 0;
		}
		if (cnt >= k) return false;
	}
	return true;
}

int bin_search(const vector<int>& stones, int k, int left, int right)
{	
	int max_val = -1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (crossable(stones, k, mid))
		{
			max_val = (max_val < mid) ? mid : max_val;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return max_val;
}

int solution(vector<int> stones, int k)
{
	int min_val = *min_element(stones.begin(), stones.end());
	int max_val = *max_element(stones.begin(), stones.end());

	return bin_search(stones, k, min_val, max_val);
}