#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int wMax = 0, hMax = 0;
    
    for(int i = 0;i < sizes.size();i++){
        if(sizes[i][0] < sizes[i][1]){
            int tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
    }
    
    for(int i = 0;i < sizes.size();i++){
        if(wMax < sizes[i][0]) wMax = sizes[i][0];
        if(hMax < sizes[i][1]) hMax = sizes[i][1];
    }
    
    return wMax * hMax;
}