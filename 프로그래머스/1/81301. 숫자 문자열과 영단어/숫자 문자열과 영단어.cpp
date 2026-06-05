#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;

int solution(string s) {
    string answer = "";
    string eng = "";
    map<string, char> m;
    stack<int> st;
    
    m["zero"] = '0';
    m["one"] = '1';
    m["two"] = '2';
    m["three"] = '3';
    m["four"] = '4';
    m["five"] = '5';
    m["six"] = '6';
    m["seven"] = '7';
    m["eight"] = '8';
    m["nine"] = '9';
    
    for(int i = 0;i < s.size();i++) {
        if(isalpha(s[i])){
            eng.push_back(s[i]);
            if(m[eng] != NULL){
                answer += m[eng];
                eng = "";
            }
        }
        else
            answer += s[i];
    }
    
    return stoi(answer);
}