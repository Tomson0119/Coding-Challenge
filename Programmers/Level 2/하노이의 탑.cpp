#include <vector>

using namespace std;

int get_sub(int n1, int n2)
{
	bool nums[3+1] = { false, false, false, false };
	nums[n1] = true;
	nums[n2] = true;
	for (int i = 1; i <= 3; i++)
	{
		if (nums[i] == false)
			return i;
	}
	return -1;
}

vector<vector<int>> hanoi(int n, int from, int to)
{
	int sub = get_sub(from, to);
	if (n == 1)
	{
		return { {from, to} };
	}
	
	vector<vector<int>> move1 = hanoi(n - 1, from, sub);
	move1.push_back({ from, to });
	vector<vector<int>> move2 = hanoi(n - 1, sub, to);
	move1.insert(move1.end(), move2.begin(), move2.end());
	return move1;
}

vector<vector<int>> solution(int n)
{
	return hanoi(n, 1, 3);
}