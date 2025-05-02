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
    int st = 0, en = 0;
    while (st < n && en < n)
    {
        if (v[en] - v[st] >= m)
        {
            minimum = min(minimum, v[en] - v[st]);
            st++;
        }
        else
        {
            en++;
        }
    }

    cout << minimum;

    return 0;
}