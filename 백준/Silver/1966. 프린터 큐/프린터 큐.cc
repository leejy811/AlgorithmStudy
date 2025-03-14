#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num;

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int n, m;
        cin >> n >> m;

        queue<pair<int, bool>> q;
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            int doc;
            cin >> doc;
            q.push(make_pair(doc, j == m));
            v.push_back(doc);
        }

        sort(v.begin(), v.end());

        int cnt = 0;
        while (!q.empty())
        {
            if (q.front().first != v[q.size() - 1])
            {
                q.push(q.front());
                q.pop();
            }
            else
            {
                cnt++;
                if (q.front().second)
                {
                    cout << cnt << "\n";
                    break;
                }
                q.pop();
            }
        }
    }

    return 0;
}