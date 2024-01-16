#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    if(s.size() != 4 && s.size() != 6)
        return false;
        
    for(auto str : s){
        if(isalpha(str)){
            answer = false;
            break;
        }
    }
    return answer;
}