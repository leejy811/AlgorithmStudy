#include <string>
using namespace std;

bool solution(string s)
{
    bool answer = false;
    int pNum = 0, yNum = 0;
    
    for(int i=0;i<s.length();i++){
        if(s[i] == 'p' || s[i] == 'P')
            pNum++;
        else if(s[i] == 'y' || s[i] == 'Y')
            yNum++;
    }
    
    answer = pNum==yNum;

    return answer;
}