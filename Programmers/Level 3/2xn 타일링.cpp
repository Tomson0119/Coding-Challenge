#include <string>
#include <vector>

using namespace std;

int counts[60'0001];

int solution(int n)
{
	counts[1] = 1;
	counts[2] = 2;

	for (int i = 3; i <= n; i++)
		counts[i] = (counts[i - 1] + counts[i - 2]) % 1'000'000'007;

	return counts[n];
}