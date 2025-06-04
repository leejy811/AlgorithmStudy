#include <bits/stdc++.h>
using namespace std;

int n;
int cnt = 0;
vector<vector<int>> v;

void func(pair<int, int> en, int state)
{
    if (en.first > n || en.second > n) return;
    if (v[en.first][en.second]) return;
    if (state == 2 && (v[en.first - 1][en.second] || v[en.first][en.second - 1])) return;

    if (en.first == n && en.second == n)
    {
        cnt++;
        return;
    }

    if (state == 0 && en.second == n) return;
    if (state == 1 && en.first == n) return;

    if (state == 0)
    {
        func({ en.first, en.second + 1 }, 0);
        func({ en.first + 1, en.second + 1 }, 2);
    }
    else if (state == 1)
    {
        func({ en.first + 1, en.second }, 1);
        func({ en.first + 1, en.second + 1 }, 2);
    }
    else if (state == 2)
    {
        func({ en.first, en.second + 1 }, 0);
        func({ en.first + 1, en.second }, 1);
        func({ en.first + 1, en.second + 1 }, 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    v.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        v[i].resize(n + 1);
        for (int j = 1; j <= n; j++)
        {
            cin >> v[i][j];
        }
    }

    func({ 1, 2 }, 0);
    cout << cnt;

    return 0;
}