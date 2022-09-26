#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int start = 0;
    int win = 0;
    for(int i=0;i<A.size();i++)
    {
        for(int j=start;j<B.size();j++)
        {
            if(A[i] < B[j])
            {
                start = j + 1;
                win += 1;
                break;
            }
        }
    }
    return win;
}