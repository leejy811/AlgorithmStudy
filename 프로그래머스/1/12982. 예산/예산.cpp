#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0, i = 0;
    
    sort(d.begin(), d.end());
    
    for(i = 0;i < d.size();i++){
        if(budget - d[i] < 0) 
            break;
        else
            budget -= d[i];
    }
    
    answer = i;
    return answer;
}