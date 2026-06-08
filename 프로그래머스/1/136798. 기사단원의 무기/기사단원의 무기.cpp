#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1;i <= number;i++){
        int cnt = 0;
        float sqrtNum = sqrt(i);
        for(int j = 1;j <= sqrtNum;j++){
            if(i % j == 0){
                if(j == sqrtNum)
                    cnt++;
                else
                    cnt += 2;
            }
        }
        
        if(cnt > limit)
            answer += power;
        else
            answer += cnt;
    }
    
    return answer;
}