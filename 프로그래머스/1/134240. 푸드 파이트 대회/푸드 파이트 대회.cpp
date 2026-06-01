#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    int n = food.size();
    
    for(int i = 1; i < n; i++)
        answer.append(food[i] / 2, i + '0');
    
    answer.push_back('0');
    
    for(int i = n - 1; i > 0; i--)
        answer.append(food[i] / 2, i + '0');
    
    return answer;
}