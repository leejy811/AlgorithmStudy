#include <bits/stdc++.h>
using namespace std;

vector<tuple<int, int, int>> tv;

bool Bellman_Ford(int st, int n)
{
    vector<int> v(n, 1e9);
    v[st] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        bool isUpdate = false;
        for (int j = 0; j < tv.size(); j++)
        {
            int s, e, c;
            tie(s, e, c) = tv[j];

            if (v[s] == 1e9) continue;
            if (v[s] + c >= v[e]) continue;

            v[e] = v[s] + c;
            isUpdate = true;
        }
        if (!isUpdate) return false;
    }

    for (int j = 0; j < tv.size(); j++)
    {
        int s, e, c;
        tie(s, e, c) = tv[j];

        if (v[s] == 1e9) continue;
        if (v[s] + c >= v[e]) continue;

        return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;
    while (t--)
    {
        int n, m, w;

        cin >> n >> m >> w;

        tv.clear();
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            tv.push_back({ a, b, c });
            tv.push_back({ b, a, c });
        }

        for (int i = 0; i < w; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--;
            b--;
            tv.push_back({ a, b, c * -1 });
        }

        bool isUpdate = false;
        for (int i = 0; i < n; i++)
        {
            if (Bellman_Ford(i, n))
            {
                isUpdate = true;
                break;
            }
        }

        cout << (isUpdate ? "YES\n" : "NO\n");
    }

    return 0;
}