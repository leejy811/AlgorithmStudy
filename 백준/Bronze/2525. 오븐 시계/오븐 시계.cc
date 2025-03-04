#include <iostream>

using namespace std;

int main()
{
    int hour, minute;
    int time;

    cin >> hour >> minute >> time;

    minute += time;

    hour += minute / 60;
    hour = hour % 24;
    minute = minute % 60;
    
    cout << hour << " " << minute;

    return 0;
}