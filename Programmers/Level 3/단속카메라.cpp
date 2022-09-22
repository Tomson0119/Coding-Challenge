#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(),
        [](const vector<int>& a, const vector<int>& b)
        {
            if(a[1] == b[1])
                return a[0] < b[0];
            return a[1] < b[1];
        });
    
    int min_val = 30001;
    int max_val = -30001;
    for(const vector<int>& vec : routes)
    {
        int in = vec[0];
        int out = vec[1];
        min_val = min(min_val, in);
        max_val = max(max_val, out);
    }
    
    int answer = 0;
    for(int i=0;i<routes.size();)
    {        
        int count = 1;
        for(int j=i+1;j<routes.size();j++)
        {
            if(routes[i][1] >= routes[j][0])
            {
                count += 1;
                continue;
            }
            break;
        }
        i += count;
        answer += 1;
    }
    return answer;
}