#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
	vector<vector<char>> graph(n + 1, vector<char>(n + 1, '.'));
	for (const auto& vec : results)
	{
		int winner = vec[0];
		int loser = vec[1];
		graph[winner][loser] = 'w';
		graph[loser][winner] = 'l';
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (graph[i][k] == 'l' && graph[k][j] == 'l')
					graph[i][j] = 'l';
                
                if (graph[i][k] == 'w' && graph[k][j] == 'w')
					graph[i][j] = 'w';
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (graph[i][j] != '.')
				cnt += 1;
		}
		if (cnt == n - 1)
			answer += 1;
	}
	return answer;
}