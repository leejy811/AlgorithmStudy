#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> vec;
    
    while(n!=0){
        vec.push_back(n%10);
        n /= 10;
    }
    
    sort(vec.begin(), vec.end());
    
    for(int i=0;i<vec.size();i++){
        answer += vec[i] * pow(10, i);
    }
    
    return answer;
}