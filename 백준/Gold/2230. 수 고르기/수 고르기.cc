#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int minimum = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int lowIdx = lower_bound(v.begin(), v.end(), v[i] + m) - v.begin();
        if (lowIdx < n)
            minimum = min(v[lowIdx] - v[i], minimum);
    }

    cout << minimum;

    return 0;
}