#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int getDigitCount(int n, const vector<bool>& broken)
{
	if (n == 0 && broken[0] == true)
		return 1;

	int cnt = 0;
	while (n > 0)
	{
		int value = n % 10;
		if (broken[value] == false)
		{
			cnt = 0;
			break;
		}
		n /= 10;
		cnt += 1;
	}
	return cnt;
}

int BFS(int start, int target, const vector<bool>& broken)
{
	queue<pair<int, int>> que;
	que.push({ target, -1 });
	que.push({ target, +1 });

	while (que.empty() == false)
	{
		int num = que.front().first;
		int dir = que.front().second;
		que.pop();

		int cnt = getDigitCount(num, broken);
		if (cnt > 0)
		{
			return cnt + abs(target - num);
		}

		if (num + dir >= 0)
			que.push({ num + dir, dir });
	}
}

bool isAllBroken(const vector<bool>& broken)
{
	for (bool e : broken)
	{
		if (e == true) return false;
	}
	return true;
}

int main()
{
	int n;
	int m;
	cin >> n >> m;

	vector<bool> broken(10, true);
	for (int i = 0; i < m; i++)
	{
		int v;
		cin >> v;
		broken[v] = false;
	}

	// 100에서 목표까지 +, -만 누를 때
	int cntWhenOnlyPlusMinusPushed = abs(n - 100);
	
	if (isAllBroken(broken))
	{
		cout << cntWhenOnlyPlusMinusPushed << "\n";
		return 0;
	}

	// 숫자 버튼을 눌러서 채널을 변경할 때
	int cntWhenNumPushed = BFS(100, n, broken);

	int answer = (cntWhenOnlyPlusMinusPushed > cntWhenNumPushed) ? cntWhenNumPushed : cntWhenOnlyPlusMinusPushed;
	cout << answer << "\n";
}