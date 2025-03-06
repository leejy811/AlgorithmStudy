#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int h, w, n;
        cin >> h >> w >> n;
        if (n % h == 0)
            cout << 100 * h + n / h << "\n";
        else
            cout << 100 * (n % h) + n / h + 1 << "\n";
    }

    return 0;
}