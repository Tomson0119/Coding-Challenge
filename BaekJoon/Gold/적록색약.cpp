#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

void PushToQueue(
	int nextR, int nextC, char color,
	vector<string>& colors,
	queue<pair<int, int>>& que, bool red_green_same)
{
	if (red_green_same && (color == 'R' || color == 'G')
		&& (colors[nextR][nextC] == 'R' || colors[nextR][nextC] == 'G'))
	{
		que.push({ nextR, nextC });
		colors[nextR][nextC] = 'X';
	}
	else if (colors[nextR][nextC] == color)
	{
		que.push({ nextR, nextC });
		colors[nextR][nextC] = 'X';
	}
}

void MarkColors(const pair<int, int>& start, vector<string>& colors, bool red_green_same)
{
	queue<pair<int, int>> que;
	que.push(start);

	char color = colors[start.first][start.second];
	colors[start.first][start.second] = 'X';

	while (que.empty() == false)
	{
		int row = que.front().first;
		int col = que.front().second;
		que.pop();

		if (row > 0)
		{
			int nextR = row - 1;
			int nextC = col;
			PushToQueue(nextR, nextC, color, colors, que, red_green_same);
		}
		if (row < colors.size() - 1)
		{
			int nextR = row + 1;
			int nextC = col;
			PushToQueue(nextR, nextC, color, colors, que, red_green_same);
		}
		if (col > 0)
		{
			int nextR = row;
			int nextC = col - 1;
			PushToQueue(nextR, nextC, color, colors, que, red_green_same);
		}
		if (col < colors[0].size() - 1)
		{
			int nextR = row;
			int nextC = col + 1;
			PushToQueue(nextR, nextC, color, colors, que, red_green_same);
		}
	}
}

pair<int, int> GetAnswer(const vector<string>& colors)
{
	vector<string> colors_a = colors;
	vector<string> colors_b = colors;

	pair<int, int> answer = { 0,0 };
	for (int i = 0; i < colors.size(); i++)
	{
		for (int j = 0; j < colors[0].size(); j++)
		{
			if (colors_a[i][j] != 'X')
			{
				MarkColors({ i, j }, colors_a, false);
				answer.first += 1;
			}

			if (colors_b[i][j] != 'X')
			{
				MarkColors({ i,j }, colors_b, true);
				answer.second += 1;
			}
		}
	}
	return answer;
}

int main()
{
	int n;
	cin >> n;

	vector<string> colors;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		colors.push_back(s);
	}

	auto res = GetAnswer(colors);
	cout << res.first << " " << res.second << "\n";
}