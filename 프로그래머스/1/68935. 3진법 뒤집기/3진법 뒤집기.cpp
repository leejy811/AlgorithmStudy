#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> tmpV;
    
    while(1) {
        if(n == 0)
            break;
        tmpV.push_back(n % 3);
        n /= 3;
    }
    
    for(int i = 0;i < tmpV.size();i++) {
        answer += tmpV[tmpV.size() - i - 1] * pow(3, i);
    }
    return answer;
}