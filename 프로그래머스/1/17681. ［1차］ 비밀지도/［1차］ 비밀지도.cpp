#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0;i < n;i++){
        int res = arr1[i] | arr2[i];
        int div = 1 << (n - 1);
        string s = "";
        for(int j = 0;j < n;j++){
            if((res / div) == 0){
                s += ' ';
            }
            else{
                res -= div;
                s += '#';
            }
            
            div = div >> 1;
        }
        answer.push_back(s);
    }
    
    return answer;
}