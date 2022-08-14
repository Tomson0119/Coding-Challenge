#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems)
{
	set<string> total_gems;
	for (const string& s : gems) total_gems.insert(s);

	vector<int> answer = { -1,-1 };
	int left = 0, right = 0;
	int min_count = -1;
	map<string, int> mapp;
	while (left <= right && right <= gems.size())
	{
		if (mapp.size() == total_gems.size())
		{			
			mapp[gems[left]] -= 1;
			if (mapp[gems[left]] == 0)
			{
				mapp.erase(gems[left]);
			}
			left += 1;
            if (min_count < 0 || min_count > (right - left + 1))
			{
				min_count = (right - left + 1);
				answer[0] = left;
				answer[1] = right;
			}
		}
		else 
		{
		    if(right < gems.size())
                mapp[gems[right]] += 1;
			right += 1;
		}
	}
	return answer;
}