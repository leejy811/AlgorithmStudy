#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for(auto sv : s) {
        char c = sv < 91 ? (sv + n - 65) % 26 + 65 : (sv + n - 97) % 26 + 97;
        isalpha(sv) ? answer.push_back(c) : answer.push_back(sv);
    }
    return answer;
}