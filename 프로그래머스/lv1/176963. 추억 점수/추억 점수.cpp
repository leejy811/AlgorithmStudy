#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> scoreMap;
    
    for(int i=0;i<name.size();i++){
        scoreMap[name[i]] = yearning[i];
    }
    
    for(int i=0;i<photo.size();i++){
        int scoreCnt = 0;
        for(int j=0;j<photo[i].size();j++){
            scoreCnt += scoreMap[photo[i][j]];
        }
        answer.push_back(scoreCnt);
    }
    return answer;
}