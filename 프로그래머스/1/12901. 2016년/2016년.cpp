#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    vector<int> days = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<string> dayOfWeek = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
    int idx = b - 1;
    for(int i = 1;i < a;i++)
        idx += days[i - 1];

    return dayOfWeek[idx % 7];
}