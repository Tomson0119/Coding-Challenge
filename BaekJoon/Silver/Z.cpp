#include <iostream>
#include <cmath>

using namespace std;

int Search(int r, int c, int order, int len, int target_r, int target_c)
{
	if (r == target_r && c == target_c)
		return order;
	
	if (len == 1)
		return -1;

	len /= 2;
	int increase = len * len;

	if (r <= target_r && r + len > target_r)
	{
		if (c <= target_c && c + len > target_c)
		{
			return Search(r, c, order, len, target_r, target_c);			
		}
		else
		{
			return Search(r, c + len, order + increase, len, target_r, target_c);
		}
	}
	else
	{
		if (c <= target_c && c + len > target_c)
		{
			return Search(r + len, c, order + increase * 2, len, target_r, target_c);
		}
		else
		{
			return Search(r + len, c + len, order + increase * 3, len, target_r, target_c);
		}
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	int n, r, c;
	cin >> n >> r >> c;

	cout << Search(0, 0, 0, pow(2, n), r, c) << "\n";
}