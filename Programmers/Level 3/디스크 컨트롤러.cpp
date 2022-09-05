#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
using int_p = pair<int, int>;

int solution(vector<vector<int>> jobs)
{
	// 현재 작업이 종료되기 전 들어온 요청 중 소요시간이 짧은 순서대로 한다.
	// 하드디스크가 놀고 있으면 요청이 들어온 순서대로 한다.

	deque<int_p> deq;  // 작업목록을 deque 컨테이너로 옮긴다.
	for (const vector<int>& job : jobs)
	{
		deq.push_back({ job[0], job[1] });
	}
	
	// 요청한 시간의 오름차순으로 정렬한다.
	// 요청 시간이 같으면 소요시간 순의 오름차순 정렬.
	sort(deq.begin(), deq.end(),
		[](const int_p& a, const int_p& b)
		{
			if (a.first == b.first)
			{
				return (a.second < b.second);
			}
			return (a.first < b.first);
		});

	int end_time = 0;
	int answer = 0;
	int_p working = { -1,-1 };
	while (deq.empty() == false)
	{
		// 현재 진행 중인 작업이 없다면
		if (working.first < 0)
		{
			working = deq.front();
			deq.pop_front();
            
			answer += working.second;
			end_time = working.second + working.first;
			continue;
		}

		// 진행 중인 작업의 종료 시간 이전에
		// 요청한 작업들을 소요시간 기준 오름차순 정렬
		sort(deq.begin(), deq.end(),
			[&end_time](const int_p& a, const int_p& b)
			{
				if (end_time > a.first && end_time > b.first)
				{
					if (a.second == b.second)
					{
						return (a.first < b.first);
					}
					return (a.second < b.second);
				}
				return (end_time > a.first);					
			});

		working = deq.front();
		deq.pop_front();
		answer += (end_time + working.second - working.first);
		end_time += working.second;
	}
	return answer / jobs.size();
}