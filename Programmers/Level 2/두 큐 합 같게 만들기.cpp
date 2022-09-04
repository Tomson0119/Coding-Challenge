#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) 
{
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0);
    if ((sum1+sum2)%2 == 1)
        return -1;
    
    int idx1 = 0;
    int idx2 = 0;
    long long answer = 0;
    while(true)
    {
        if (sum1 == sum2) 
        {
            break;
        }
        else if(sum1 > sum2) 
        {
            if (idx1 < queue1.size()) 
            {
                sum2 += queue1[idx1];
                sum1 -= queue1[idx1];
            }
            else if (idx1 < queue1.size() + queue2.size())
            {
                sum2 += queue2[idx1 - queue1.size()];
                sum1 -= queue2[idx1 - queue1.size()];
            }
            else
            {
                answer = -1;
                break;
            }
            idx1 += 1;
        }
        else {
            if (idx2 < queue2.size())
            {
                sum1 += queue2[idx2];
                sum2 -= queue2[idx2];
            }
            else if (idx2 < queue2.size() + queue1.size())
            {
                sum1 += queue1[idx2 - queue2.size()];
                sum2 -= queue1[idx2 - queue2.size()];
            }
            else
            {
                answer = -1;
                break;
            }
            idx2 += 1;
        }
        answer += 1;
    }
    return answer;
}