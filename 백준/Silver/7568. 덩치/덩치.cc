#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (pair<int, int> p : v)
        {
            if (p.first > v[i].first && p.second > v[i].second)
                cnt++;
        }
        cout << cnt + 1 << " ";
    }

    return 0;
}