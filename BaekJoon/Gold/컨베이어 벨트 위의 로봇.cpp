#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<pair<int, bool>>& belt)
{
	pair<int, bool> last = belt.back();
	for (int i = belt.size() - 1; i >= 0; i--)
	{
		// 벨트 회전
		if (i > 0)
			belt[i] = move(belt[i - 1]);
		else
			belt[i] = move(last);
		
		// 내리는 위치의 로봇 제거
		if (i == belt.size() / 2 - 1)
			belt[i].second = false;

		// 조건에 따라 로봇을 앞으로 이동
		if (i < belt.size() - 1 && belt[i].second 
			&& belt[i + 1].second == false && belt[i+1].first > 0)
		{
			belt[i + 1].first -= 1;
			belt[i + 1].second = true;
			belt[i].second = false;
		}
	}
}

int get_zeros(const vector<pair<int, bool>>& belt)
{
	int ret = 0;
	for (const pair<int, bool>& p : belt)
	{
		if (p.first == 0)
			ret += 1;
	}
	return ret;
}

int main()
{
	int n, k;
	cin >> n >> k;

	vector<pair<int, bool>> belt(2 * n, { 0,false });
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> belt[i].first;
	}

	int process = 1;
	for (;;process++)
	{
		// 1. 벨트 회전
		// 2. 올라간 순서대로 로봇 이동
		rotate(belt);
		belt[n-1].second = false;

		// 3. 올리는 위치에 로봇 올림
		if (belt.front().first > 0)
		{
			belt.front().first -= 1;
			belt.front().second = true;
		}

		// 4. 내구도가 0인 칸이 k개 이상이면 종료
		if (get_zeros(belt) >= k) break;
	}
	cout << process << "\n";
}