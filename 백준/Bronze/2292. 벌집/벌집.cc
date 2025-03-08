#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    if (n == 1)
    {
        cout << "1";
        return 0;
    }

    int p = 1 + 6;
    int cnt = 2;
    while (1)
    {
        if ((n - 1) / p == 0) break;
        p += cnt * 6;
        cnt++;
    }

    cout << cnt;

    return 0;
}