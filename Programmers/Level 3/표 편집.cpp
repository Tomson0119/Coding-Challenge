#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

struct Node
{
	int num;
	Node* prev;
	Node* next;
    
    Node(int n, Node* prv, Node* nxt)
        : num{ n }, prev{ prv }, next{ nxt }
    {        
    }
};

void initList(vector<unique_ptr<Node>>& nodes)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i] = make_unique<Node>(i, nullptr, nullptr);
		if (i > 0)
		{
			nodes[i - 1]->next = nodes[i].get();
			nodes[i]->prev = nodes[i - 1].get();
		}
	}
}

void moveLeft(Node*& current, int mov)
{
	while (current->prev && mov--)
	{
		// can't be null
		current = current->prev;
	}
}

void moveRight(Node*& current, int mov)
{
	while (current->next && mov--)
	{
		// can't be null
		current = current->next;
	}
}

void eraseNode(Node*& current)
{
    if(current == nullptr) return;
    
	if (current->prev)
	{
		current->prev->next = current->next;
	}
	if (current->next)
	{
		current->next->prev = current->prev;
	}
	current = (current->next) ? current->next : current->prev;
}

void restoreNode(vector<unique_ptr<Node>>& nodes, int idx)
{
    Node* temp = nodes[idx].get();
    
	if (temp->prev)
	{
		temp->prev->next = temp;
	}
	if (temp->next)
	{
		temp->next->prev = temp;
	}
}

void excuteCmd(vector<unique_ptr<Node>>& nodes, Node*& current, vector<int>& stk, const string& command)
{
	char c = command.front();
	switch (c)
	{
	case 'U':
	{
		int mov = stoi(command.substr(2));
		moveLeft(current, mov);
		break;
	}
	case 'D':
	{
		int mov = stoi(command.substr(2));
		moveRight(current, mov);
		break;
	}
	case 'C':
	{
		stk.push_back(current->num);
		eraseNode(current);
		break;
	}
	case 'Z':
	{
        if(stk.empty()==false)
        {
            int idx = stk.back();
            stk.pop_back();
            restoreNode(nodes, idx);
            break;
        }
	}
	}
}

string solution(int n, int k, vector<string> cmd)
{
	vector<unique_ptr<Node>> nodes(n);
	initList(nodes);
	Node* current = nodes[k].get();

	vector<int> stk;

	for (const string& s : cmd)
	{
		excuteCmd(nodes, current, stk, s);
	}

	string result;
    while(current->prev) current = current->prev;
	for (int i = 0; i < n; i++)
	{
		if (current && current->num == i)
		{
			result += 'O';
			current = current->next;
		}
		else
			result += 'X';
	}
	return result;
}

int main()
{
	cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" }) << endl;
	cout << solution(8, 2, { "D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C" }) << endl;
}