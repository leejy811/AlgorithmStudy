#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    
    int a, b;

    cin >> a >> b;

    for (int i = 0; i < 3; i++)
    {
        cout << a * ((b % (int)pow(10, i + 1)) / (int)pow(10, i)) << "\n";
    }

    cout << a * b;
    
    return 0;
}
