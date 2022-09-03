#include <vector>
#include <numeric>

using namespace std;

vector<int> solution(int n, long long k)
{
	vector<long long> dp(n+1, 0);
	dp[0] = 0;
	dp[1] = 1;
	for (long long i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] * i;
	}

	vector<int> people(n, 0);
	iota(people.begin(), people.end(), 1);

	vector<int> answer;
	for (int j = 1; j < n; j++)
	{
		int idx = (k - 1) / dp[n - j];
		answer.push_back(people[idx]);
		people.erase(people.begin() + idx);
		if (idx > 0)
		{
			k -= dp[n - j] * idx;
		}
	}
	answer.push_back(people[0]);
	return answer;
}