#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int maxX = 0, maxY = 0, minX = wallpaper[0].length(), minY = wallpaper.size();
    
    for(int i=0;i<wallpaper.size();i++){
        for(int j=0;j<wallpaper[i].length();j++){
            if(wallpaper[i][j] == '#'){
                if(j < minX) minX = j;
                if(j+1 > maxX) maxX = j+1;
                if(i < minY) minY = i;
                if(i+1 > maxY) maxY = i+1;
            }
        }
    }
    
    answer = {minY, minX, maxY, maxX};
    return answer;
}