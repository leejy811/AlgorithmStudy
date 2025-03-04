#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int byte;

    cin >> byte;

    byte /= 4;
    for (int i = 0; i < byte; i++)
    {
        cout << "long ";
    }

    cout << "int";

    return 0;
}