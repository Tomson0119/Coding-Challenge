#include <vector>
#include <cmath>

using namespace std;
using llong = long long;

int getTargetNode(const vector<pair<llong, vector<int>>>& graph)
{
	int max_cnt = -1;
	int target = -1;
	int i = 0;
	for (const pair<int, vector<int>>& p : graph)
	{
		int cnt = 0;
		for (int node : p.second)
		{
			if (graph[node].first > 0)
			{
				cnt += 1;
			}
		}
		if (max_cnt < cnt)
		{
			max_cnt = cnt;
			target = i;
		}
		i += 1;
	}
	return target;
}

llong makeWeightsZero(
	vector<pair<llong, vector<int>>>& graph, 
	int node,
	vector<bool>& visited)
{
	visited[node] = true;
	llong cnt = 0;
	for (int other : graph[node].second)
	{
		if (visited[other] == false)
		{
			cnt += makeWeightsZero(graph, other, visited);
			cnt += abs(graph[other].first);
			graph[node].first += graph[other].first;
			graph[other].first = 0;
		}
	}	
	return cnt;
}

llong solution(vector<int> a, vector<vector<int>> edges)
{
	vector<pair<llong, vector<int>>> graph(a.size());
	for (const vector<int>& edge : edges)
	{
		graph[edge[0]].first = a[edge[0]];
		graph[edge[0]].second.push_back(edge[1]);

		graph[edge[1]].first = a[edge[1]];
		graph[edge[1]].second.push_back(edge[0]);
	}
	vector<bool> visited(a.size(), false);
	int target = getTargetNode(graph);
	llong answer = makeWeightsZero(graph, getTargetNode(graph), visited);
	return (graph[target].first == 0) ? answer : -1;
}