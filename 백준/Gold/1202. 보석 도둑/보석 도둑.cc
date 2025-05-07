#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;

    cin >> n >> k;

    priority_queue<pair<int, int>> pq;
    multiset<int> s;
    for (int i = 0; i < n; i++)
    {
        int m, v;
        cin >> m >> v;
        pq.push({ v, m });
    }

    for (int i = 0; i < k; i++)
    {
        int c;
        cin >> c;
        s.insert(c);
    }

    long long value = 0;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = pq.top();

        if (s.lower_bound(p.second) != s.end())
        {
            s.erase(s.lower_bound(p.second));
            value += p.first;
        }

        pq.pop();
    }

    cout << value;

    return 0;
}