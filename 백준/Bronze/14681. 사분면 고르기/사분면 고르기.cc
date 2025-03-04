#include <iostream>

using namespace std;

int main()
{
    int x, y;
    int quadrant = 1;

    cin >> x >> y;

    if (x > 0 && y > 0)
        quadrant = 1;
    else if (x < 0 && y > 0)
        quadrant = 2;
    else if (x < 0 && y < 0)
        quadrant = 3;
    else if (x > 0 && y < 0)
        quadrant = 4;
    
    cout << quadrant;

    return 0;
}