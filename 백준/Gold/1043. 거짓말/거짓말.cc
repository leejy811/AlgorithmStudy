#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int t;
    cin >> t;
    set<int> tv;
    for (int i = 0; i < t; i++)
    {
        int x;
        cin >> x;
        tv.insert(x);
    }

    vector<vector<int>> v(m);
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        v[i].resize(num);
        for (int j = 0; j < num; j++)
            cin >> v[i][j];
    }

    vector<bool> p(m);
    int cnt = 1;
    while (cnt != 0)
    {
        cnt = 0;

        for (int i = 0; i < m; i++)
        {
            if (p[i]) continue;

            for (int j = 0; j < v[i].size(); j++)
            {

                if (find(tv.begin(), tv.end(), v[i][j]) != tv.end())
                {
                    cnt++;
                    p[i] = true;
                    for (int k = 0; k < v[i].size(); k++)
                        tv.insert(v[i][k]);
                    break;
                }
            }
        }
    }

    cnt = 0;
    for (int i = 0; i < m; i++)
    {
        if (!p[i]) cnt++;
    }

    cout << cnt;

    return 0;
}