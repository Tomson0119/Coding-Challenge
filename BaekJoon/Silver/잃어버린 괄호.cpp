#include <iostream>
#include <deque>
#include <sstream>

using namespace std;

void Split(string& s, deque<pair<int, char>>& deq)
{
	stringstream ss(s);

	int n;
	char op;
	while (ss >> n)
	{
		char op = 'x';
		ss >> op;

		deq.push_back({ n, op });
	}
}

void Calc(deque<pair<int, char>>& deq, int pos)
{
	if (pos == deq.size() - 1) return;

	switch (deq[pos].second)
	{
	case 'x':
		return;

	case '+':
		deq[pos + 1].first = deq[pos].first + deq[pos + 1].first;
		break;

	case '-':
		deq[pos + 1].first = deq[pos].first - deq[pos + 1].first;
		break;
	}
	deq.erase(deq.begin() + pos);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;

	deque<pair<int, char>> deq;
	Split(s, deq);
	
	for (int i = 0; i < deq.size() - 1; i++)
	{
		while (deq[i].second == '+')
			Calc(deq, i);
	}

	while (deq.size() > 1)
	{
		Calc(deq, 0);
	}
	cout << deq[0].first << "\n";
}