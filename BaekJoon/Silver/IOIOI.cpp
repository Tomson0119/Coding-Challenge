#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	string s;
	cin >> s;
	
	int cnt = 0;
	char next = 'I';
	vector<int> counts;
	for (int i = 0; i < m; i++)
	{
		if (s[i] == next)
		{
			if (next == 'I') next = 'O';
			else
			{
				next = 'I';
				cnt += 1;
			}
		}
		else
		{
			if (cnt > 0)
			{
				if (next == 'I') cnt -= 1;
				counts.push_back(cnt);
			}
			cnt = 0;
		}
	}
    if (cnt > 0)
	{
		if (next == 'I') cnt -= 1;
		counts.push_back(cnt);
	}

	int answer = 0;
	for (int e : counts)
	{
		if (e >= n) answer += 1 + (e - n);
	}
	cout << answer << "\n";
}