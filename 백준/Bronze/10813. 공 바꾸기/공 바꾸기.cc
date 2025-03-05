#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int i, j, k;

    cin >> n >> m;

    vector<int> basket;

    for (int p = 1; p <= n; p++)
    {
        basket.push_back(p);
    }

    for (int p = 0; p < m; p++)
    {
        cin >> i >> j;
        swap(basket[i - 1], basket[j - 1]);
    }

    for (int a : basket)
    {
        cout << a << " ";
    }

    return 0;
}