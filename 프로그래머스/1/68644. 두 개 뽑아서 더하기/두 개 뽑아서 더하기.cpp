#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<bool> exists(201);
    
    for(int i = 0; i < numbers.size(); i++)
        for(int j = i + 1; j < numbers.size(); j++)
            exists[numbers[i] + numbers[j]] = true;
    
    for(int i = 0; i < exists.size(); i++)
        if(exists[i])
            answer.push_back(i);
    
    return answer;
}