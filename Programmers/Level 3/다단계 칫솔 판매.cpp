#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <unordered_map>
#include <cmath>

using namespace std;

struct Node
{
	string name;
	int amount;

	Node* parent;
	vector<Node*> children;
};

void CreateNewNode(const string& name, const string& parent, 
	unordered_map<string, unique_ptr<Node>>& nodes)
{
	if (nodes.find(parent) == nodes.end())
	{
		nodes[parent] = make_unique<Node>();
		nodes[parent]->name = parent;
		nodes[parent]->amount = 0;
		nodes[parent]->parent = nullptr;
	}
	
	nodes[name] = make_unique<Node>();
	nodes[name]->name = name;
	nodes[name]->amount = 0;
	nodes[name]->parent = nodes[parent].get();

	nodes[parent]->children.push_back(nodes[name].get());
}

void AddAmount(int amount, const string& name, unordered_map<string, unique_ptr<Node>>& nodes)
{
	int tenPercent = floor(amount * 0.1f);
	if (tenPercent >= 1)
	{
		nodes[name]->amount += amount - tenPercent;

		if (nodes[name]->parent != nullptr)
			AddAmount(tenPercent, nodes[name]->parent->name, nodes);
	}
	else
		nodes[name]->amount += amount;
}

vector<int> solution(
	vector<string> enroll,
	vector<string> referral,
	vector<string> seller,
	vector<int> amount)
{
	unordered_map<string, unique_ptr<Node>> nodes;

	for (int i = 0; i < enroll.size(); i++)
	{
		const string& name = enroll[i];
		const string& parent = referral[i];
		CreateNewNode(name, parent, nodes);
	}

	for (int k = 0; k < seller.size(); k++)
	{
		const string& name = seller[k];
		int amnt = amount[k];
		AddAmount(amnt * 100, name, nodes);
	}	

	vector<int> answer;
	for (const string& name : enroll)
		answer.push_back(nodes[name]->amount);
	return answer;
}