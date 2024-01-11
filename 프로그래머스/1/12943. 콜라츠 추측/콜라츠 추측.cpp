#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long ln = num;
    
    while(ln != 1) {
        if(answer == 500){
            answer = -1;
            break;
        }
        ln % 2 == 0 ? ln /= 2 : ln = ln * 3 + 1;
        answer++;
    }
    
    return answer;
}