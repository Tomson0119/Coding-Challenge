#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    while(n > 0)
    {
        int mid = s / n;
        if(mid==0) return {-1};
        s -= mid;
        n -= 1;
        answer.push_back(mid);
    }        
    return answer;
}