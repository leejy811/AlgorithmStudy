#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long sq = sqrt(n);
    if(sq*sq == n)
        answer = pow(sq+1, 2);
    else
        answer = -1;
    return answer;
}