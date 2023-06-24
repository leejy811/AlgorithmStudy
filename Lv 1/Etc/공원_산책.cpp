#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int i, j;
    map<char, vector<int>> dirMap;

    dirMap['E'] = { 0, 1 };
    dirMap['W'] = { 0, -1 };
    dirMap['N'] = { -1, 0 };
    dirMap['S'] = { 1, 0 };

    for (i = 0; i < park.size(); i++) {
        if (park[i].find('S') != string::npos) {
            answer.push_back(i);
            answer.push_back(park[i].find('S'));
            break;
        }
    }

    for (i = 0; i < routes.size(); i++) {
        int distance = routes[i][2] - '0';
        vector<int> resTemp = { answer[0], answer[1] };
        for (j = 0; j < distance; j++) {
            resTemp[0] += dirMap[routes[i][0]].front();
            resTemp[1] += dirMap[routes[i][0]].back();
            if (resTemp[0] < 0 || resTemp[0] >= park.size() || resTemp[1] < 0 || resTemp[1] >= park[resTemp[0]].length())
                break;
            else if (park[resTemp[0]][resTemp[1]] == 'X')
                break;
        }
        if (j == distance)
            answer = resTemp;
    }

    return answer;
}