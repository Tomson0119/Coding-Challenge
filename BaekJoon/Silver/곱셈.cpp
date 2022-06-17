#include <iostream>

using namespace std;

long long solve(long long a, long long b, long long c)
{
	if (b == 0) return 1;

	if (b % 2 == 0)
	{
		long long val = solve(a, b / 2, c);
		val *= val;
		val %= c;
		return val;
	}
	else
	{
		long long val = solve(a, (b - 1) / 2, c);
		val *= val;
		val %= c;
		val *= a;
		val %= c;
		return val;
	}
}

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	
	cout << solve(a, b, c) << endl;
}