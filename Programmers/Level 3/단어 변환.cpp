#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int countOfDiffLetters(const string& s, const string& word)
{
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != word[i]) cnt += 1;
	}
	return cnt;
}

int solution(string begin, string target, vector<string> words)
{
	queue<pair<string, int>> que;
	que.push({ begin, 0 });

	unordered_set<string> visited;
	while (que.empty() == false)
	{
		string s = que.front().first;
		int cnt = que.front().second;
		que.pop();

		if (s == target)
			return cnt;

		if (visited.find(s) != visited.end()) continue;
		visited.insert(s);

		for (const string& word : words)
		{
			if (countOfDiffLetters(s, word) == 1)
				que.push({ word, cnt + 1 });
		}
	}
	return 0;
}

int main()
{
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }) << "\n";
	cout << solution("hit", "cog", { "hot", "dot", "dog", "lot", "log" }) << "\n";
}