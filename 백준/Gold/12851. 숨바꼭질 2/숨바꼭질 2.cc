#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;

    cin >> n >> k;

    queue<pair<int, int>> q;
    vector<bool> visit(100005);

    q.push(make_pair(n, 0));

    int min = 0;
    while (!q.empty())
    {
        pair<int, int> f = q.front();

        if (f.first == k)
        {
            min = f.second;
            break;
        }

        q.pop();
        visit[f.first] = true;

        if (f.first > 1e5) continue;

        if (f.first != 0 && !visit[f.first - 1])
            q.push(make_pair(f.first - 1, f.second + 1));

        if (f.first < k && !visit[f.first + 1])
            q.push(make_pair(f.first + 1, f.second + 1));

        if (f.first < k && f.first * 2 <= 1e5 && !visit[f.first * 2])
            q.push(make_pair(f.first * 2, f.second + 1));
    }

    int cnt = 0;
    while (!q.empty())
    {
        pair<int, int> f = q.front();

        if (f.first == k && min == f.second)
            cnt++;

        q.pop();
        visit[f.first] = true;

        if (f.first > 1e5) continue;

        if (f.first != 0 && !visit[f.first - 1])
            q.push(make_pair(f.first - 1, f.second + 1));

        if (f.first < k && !visit[f.first + 1])
            q.push(make_pair(f.first + 1, f.second + 1));

        if (f.first < k && f.first * 2 <= 1e5 && !visit[f.first * 2])
            q.push(make_pair(f.first * 2, f.second + 1));
    }

    cout << min << '\n' << cnt;

    return 0;
}