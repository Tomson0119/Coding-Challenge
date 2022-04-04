#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void BFS(int n, 
	const vector<vector<int>>& parties,
	const vector<vector<int>>& attendees,
	vector<bool>& knows)
{
	queue<int> que;
	que.push(n);

	while (que.empty() == false)
	{
		int person = que.front();
		que.pop();

		for (int party : parties[person])
		{
			for (int attendee : attendees[party])
			{
				if (knows[attendee] == false)
				{
					knows[attendee] = true;
					que.push(attendee);
				}
			}
		}
	}
}

void checkPeopleKnowsTruth(
	const vector<vector<int>>& parties,
	const vector<vector<int>>& attendees,
	vector<bool>& knows)
{
	for (int i = 1; i < knows.size(); i++)
	{
		if (knows[i])
		{
			BFS(i, parties, attendees, knows);
		}
	}
}

int getCntOfPossibleLie(const vector<bool>& knows, const vector<vector<int>>& attendees)
{
	int cnt = 0;
	for (const vector<int>& vec : attendees)
	{
		bool flag = false;
		for (int e : vec)
		{
			if (knows[e])
			{
				flag = true;
				break;
			}
		}
		if (flag == false) cnt += 1;
	}
	return cnt;
}

int main()
{
	int n, m;
	cin >> n >> m;

	int k;
	cin >> k;
	
	vector<bool> knows(n+1, false);
	for (int i = 0; i < k; i++)
	{
		int v;
		cin >> v;
		knows[v] = true;
	}

	vector<vector<int>> parties(n+1);
	vector<vector<int>> attendees(m);
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;

		bool flag = false;
		for (int j = 0; j < k; j++)
		{
			int v;
			cin >> v;

			parties[v].push_back(i);
			attendees[i].push_back(v);
		}
	}

	checkPeopleKnowsTruth(parties, attendees, knows);
	
	cout << getCntOfPossibleLie(knows, attendees) << "\n";
}