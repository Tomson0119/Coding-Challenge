#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int rotateLeft(int n)
{
	int left = n / 1000;
	n -= left * 1000;
	n = n * 10 + left;
	return n;
}

int rotateRight(int n)
{
	int right = n % 10;
	n = n / 10 + right * 1000;
	return n;
}

string BFS(int a, int b)
{
	queue<pair<int, string>> que;
	que.push({ a, "" });
	
	vector<bool> visited(10'000, false);
	while (que.empty() == false)
	{
		int n = que.front().first;
		string op = que.front().second;
		que.pop();

		if (visited[n] == true) continue;
		visited[n] = true;

		int next = 0;
		// D
		next = (2 * n) % 10000;
		if (next == b) return op + 'D';
		que.push({ next, op + 'D' });

		// S
		next = (n - 1 < 0) ? 9999 : n - 1;
		if (next == b) return op + 'S';
		que.push({ next, op + 'S'});

		// L
		next = rotateLeft(n);
		if (next == b) return op + 'L';
		que.push({ next, op + 'L' });

		// R
		next = rotateRight(n);
		if (next == b) return op + 'R';
		que.push({ next, op + 'R'});
	}
	return "";
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << BFS(a, b) << "\n";
	}
}