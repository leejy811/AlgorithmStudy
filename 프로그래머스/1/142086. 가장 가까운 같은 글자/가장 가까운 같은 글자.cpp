#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    for(int i = 0;i < s.size();i++) {
        int cnt = count(s.begin(), s.begin() + i, s[i]);
        if(cnt != 0) {
            int it = 0;
            for(int j = 0;j < cnt;j++){
                if(j != 0) it++;
                it = find(s.begin() + it, s.begin() + i, s[i]) - s.begin();
            }
            answer.push_back(i - it);
        }
        else
            answer.push_back(-1);
    }
    return answer;
}