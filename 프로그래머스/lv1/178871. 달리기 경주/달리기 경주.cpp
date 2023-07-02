
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> playerMap;
    
    for(int i = 0; i < players.size(); i++)
        playerMap[players[i]] = i;
    
    for(int i = 0; i < callings.size(); i++) {
        int idx = playerMap[callings[i]];
        swap(players[idx], players[idx-1]);
        playerMap[players[idx]] = idx;
        playerMap[players[idx-1]] = idx-1;
    }
    
    answer = players;
    return answer;
}