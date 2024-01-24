#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int j = 0;
    
    for(int i = 0;i < s.size();i++) {
        if(!isalpha(s[i])){
            j = 0;
            continue;
        }
        s[i] = j % 2 == 0 ? toupper(s[i]) : tolower(s[i]);
        j++;
    }
    return s;
}