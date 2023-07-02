#include <cmath>

int solution(int n)
{
    int answer = 0, i = 1;
    
    while(true){
        answer += n % (int)pow(10, i) / (int)pow(10, i-1);
        i++;
        if(n==n % (int)pow(10, i-1))
            break;
    }

    return answer;
}