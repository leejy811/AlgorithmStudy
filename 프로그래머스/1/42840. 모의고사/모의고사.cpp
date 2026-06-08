#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<vector<int>> patterns = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    vector<int> cnts(3, 0);
    vector<int> results(3, 0);
    
    for(int i = 0;i < answers.size();i++){
        for(int j = 0;j < 3;j++){
            if(patterns[j][cnts[j]] == answers[i])
                results[j]++;
            
            cnts[j] = (cnts[j] + 1) % patterns[j].size();
        }
    }
    
    vector<int> answer;
    int maxElem = *max_element(results.begin(), results.end());
    for(int i = 0;i < 3;i++){
        if(results[i] == maxElem)
            answer.push_back(i + 1);
    }
    
    return answer;
}