#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> que{works.begin(), works.end()};
    while(n--)
    {
        int val = que.top();
        que.pop();
        que.push(--val);
    }
    
    long long answer = 0;
    while(que.empty()==false)
    {
        int val = que.top();
        if(val > 0)
            answer += val * val;
        que.pop();
    }
    return answer;
}