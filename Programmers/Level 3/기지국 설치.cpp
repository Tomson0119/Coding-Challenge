#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int get_antenna(int count, int len)
{
    if (count <= 0) return 0;
    
    if(count % len == 0)
    {
        return count / len;
    }
    else
    {
        return ceil((float)count / len);
    }
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    int len = w * 2 + 1;
    for(int i=0;i<stations.size();i++)
    {
        int loc = stations[i];
        int curr_left = max(1, loc-w);
        int curr_right = min(n, loc+w);
        
        int count = curr_left - 1;
        if(i > 0)
        {
            int prev = stations[i-1];
            int prev_left = max(1, prev-w);
            int prev_right = min(n, prev+w);
            
            count = curr_left - prev_right - 1;
        }
        answer += get_antenna(count, len);
        
        if(i == stations.size() - 1)
        {
            answer += get_antenna(n - curr_right, len);
        }
    }
    return answer;
}