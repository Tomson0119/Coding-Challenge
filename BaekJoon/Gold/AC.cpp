#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void printResult(const string& nums, int len, int beg, int end, bool rev)
{
	stringstream ss(nums);

	vector<int> digits(len);
	for (int i = 0; i < len; i++)
	{
		char c;
		int num;
		ss >> c >> num;
		digits[i] = num;
	}

	cout << "[";
	if (rev==false)
	{
		for (int i = beg; i < end; i++)
		{
			cout << digits[i];
			if (i < end - 1) cout << ",";
		}
	}
	else
	{
		for (int i = end - 1; i >= beg; i--)
		{
			cout << digits[i];
			if (i > beg) cout << ",";
		}
	}
	cout << "]\n";
}

void solve(const string& commands, int n, const string& nums)
{
	bool rev = false;
	int beg = 0;
	int end = n;
	for (char cmd : commands)
	{
		switch (cmd)
		{
		case 'R':
			rev = !rev;
			break;

		case 'D':
			if (rev) end -= 1;
			else beg += 1;

			if (beg > end)
			{
				cout << "error\n";
				return;
			}
			break;
		}
	}
	printResult(nums, n, beg, end, rev);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		string commands, nums;
		int n;
		cin >> commands >> n >> nums;
		
		solve(commands, n, nums);
	}
}