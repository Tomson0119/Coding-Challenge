#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    map<char, int> categories;
    int middle = 4;    
    for(int i=0;i<survey.size();i++) {
        char disagree = survey[i][0];
        char agree = survey[i][1];
        
        if (choices[i] < middle) {
            int increase = middle - choices[i];
            categories[disagree] += increase;
        }
        else if(choices[i] > middle) {
            int increase = choices[i] - middle;
            categories[agree] += increase;
        }
    }

    vector<pair<char,char>> category_pairs = {
        {'R', 'T'},
        {'C', 'F'},
        {'J', 'M'},
        {'A', 'N'}
    };
    
    string answer = "";
    for(const auto& p : category_pairs) {
        int a_result = categories[p.first];
        int b_result = categories[p.second];
        if(a_result > b_result) {
            answer += p.first;
        }
        else if(a_result < b_result) { 
            answer += p.second;
        }
        else {
            char target = (p.first < p.second) ? p.first : p.second;
            answer += target;
        }
    }
    return answer;
}