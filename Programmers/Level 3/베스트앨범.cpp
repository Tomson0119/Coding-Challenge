#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{
	unordered_map<string, vector<int>> hash1;
	unordered_map<string, int> hash2;
	
	for (int i=0;i<genres.size();i++)
	{
		if (hash1.find(genres[i]) == hash1.end())
		{
			hash1[genres[i]] = { i };
			hash2[genres[i]] = plays[i];
		}
		else
		{
			hash1[genres[i]].push_back(i);
			hash2[genres[i]] += plays[i];
		}
	}
	
	vector<pair<string, int>> temp(hash2.begin(), hash2.end());
	sort(temp.begin(), temp.end(), [](const auto& a, const auto& b)
		{
			return a.second > b.second;
		});

	for (auto& [_, vec] : hash1)
	{
		sort(vec.begin(), vec.end(), 
			[&plays](int a, int b)
			{
				if (plays[a] == plays[b])
					return a < b;
				return plays[a] > plays[b];
			});
	}

	vector<int> answer;
	for (const auto& p : temp)
	{
		for (int i=0; i < 2 && i < hash1[p.first].size(); i++)
		{
			answer.push_back(hash1[p.first][i]);
		}
	}	

	return answer;
}

int main()
{
	auto vec = solution(
		{ "classic", "pop", "classic", "classic", "pop" },
		{ 500, 600, 150, 800, 2500 });

	for (int e : vec)
		cout << e << " ";
	cout << "\n";
}