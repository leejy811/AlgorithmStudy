#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int maxWeight = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        maxWeight = max(maxWeight, v[i] * (n - i));
    }

    cout << maxWeight;

    return 0;
}