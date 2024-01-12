#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for (auto a : arr){
        if(a % divisor == 0)
            answer.push_back(a);
        else if(answer.empty() && a == arr.back())
            answer.push_back(-1);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}