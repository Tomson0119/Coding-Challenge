#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void TravelNetwork(const vector<vector<int>>& computer, vector<bool>& visited, int idx)
{
	deque<int> stk;
	stk.push_back(idx);

	while (stk.empty() == false)
	{
		int num = stk.back();
		stk.pop_back();

		if (visited[num] == true)
			continue;

		visited[num] = true;

		for (int i = 0; i < computer[num].size(); i++)
		{
			if (computer[num][i] == 1)
				stk.push_back(i);
		}
	}
}

int solution(int n, vector<vector<int>> computer)
{
	int answer = 0;
	vector<bool> visited(computer.size(), false);
	for (int i = 0; i < computer.size(); i++)
	{
		if (visited[i] == false)
		{
			TravelNetwork(computer, visited, i);
			answer += 1;
		}
	}
	return answer;
}

int main()
{
	cout << solution(3, { {1,1,0}, {1,1,0}, {0,0,1} }) << "\n";
	cout << solution(3, { {1,1,0}, {1,1,1}, {0,1,1} }) << "\n";
}