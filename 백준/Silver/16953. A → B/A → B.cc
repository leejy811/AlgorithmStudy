#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;

    queue<pair<long long, long long>> q;
    q.push({ a, 1 });

    while (!q.empty())
    {
        pair<long long, long long> p = q.front();
        q.pop();

        if (p.first * 2 > b) continue;

        if (p.first * 2 == b)
        {
            cout << p.second + 1;
            return 0;
        }
        q.push({ p.first * 2, p.second + 1 });

        if (p.first * 10 + 1 == b)
        {
            cout << p.second + 1;
            return 0;
        }
        q.push({ p.first * 10 + 1, p.second + 1 });
    }

    cout << -1;

    return 0;
}