#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        vector<bool> vis(10001);
        queue<pair<int, string>> q;
        q.push({ a, "" });

        while (!q.empty())
        {
            int n;
            string cmd;
            tie(n, cmd) = q.front();
            q.pop();
            if (n == b)
            {
                cout << cmd << '\n';
                break;
            }

            int d = (2 * n) % 10000;
            int s = (n == 0) ? 9999 : n - 1;

            int dig[5] = {};
            for (int i = 1; i <= 4; i++)
            {
                dig[i] = n % 10;
                n /= 10;
            }

            int l = ((dig[3] * 10 + dig[2]) * 10 + dig[1]) * 10 + dig[4];
            int r = ((dig[1] * 10 + dig[4]) * 10 + dig[3]) * 10 + dig[2];

            if (!vis[d])
            {
                q.push({ d, cmd + 'D' });
                vis[d] = true;
            }
            if (!vis[s])
            {
                q.push({ s, cmd + 'S' });
                vis[s] = true;
            }
            if (!vis[l])
            {
                q.push({ l, cmd + 'L' });
                vis[l] = true;
            }
            if (!vis[r])
            {
                q.push({ r, cmd + 'R' });
                vis[r] = true;
            }
        }
    }


    return 0;
}