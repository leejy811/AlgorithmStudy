#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int i, j, k;

    cin >> n >> m;

    vector<int> basket(n, 0);

    for (int p = 0; p < m; p++)
    {
        cin >> i >> j >> k;
        for (int q = i - 1; q < j; q++)
        {
            basket[q] = k;
        }
    }

    for (int a : basket)
    {
        cout << a << " ";
    }

    return 0;
}