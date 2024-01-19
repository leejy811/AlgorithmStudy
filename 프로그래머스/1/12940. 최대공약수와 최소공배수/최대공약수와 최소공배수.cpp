#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer(2);
    
    for(int i = 1;i <= min(m, n);i++) {
        if(n % i == 0 && m % i == 0)
            answer[0] = i;
    }
    
    for(int i = max(m, n);i <= m * n;i++) {
        if(i % m == 0 && i % n == 0) {
            answer[1] = i;
            break;
        }
    }
    
    return answer;
}