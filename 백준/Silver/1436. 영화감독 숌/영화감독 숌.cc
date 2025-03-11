#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    int cnt = 0, i = 666;
    while (1)
    {
        if (to_string(i).find("666") != string::npos) cnt++;
        if (cnt == n) break;
        i++;
    }

    cout << i;

    return 0;
}