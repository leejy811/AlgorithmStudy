#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    answer = s.size() % 2 == 0 ? s.substr(s.size() / 2 - 1, 2) : s.substr(s.size() / 2, 1);
    return answer;
}