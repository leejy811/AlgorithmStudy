#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> vc;
vector<vector<bool>> vb;
int n, m, cnt = 0;

void Visit(int x, int y)
{
    if (vc[x][y] == 'P')
        cnt++;

    vb[x][y] = true;

    if (x + 1 < n && !vb[x + 1][y] && vc[x + 1][y] != 'X')
        Visit(x + 1, y);
    if (x - 1 >= 0 && !vb[x - 1][y] && vc[x - 1][y] != 'X')
        Visit(x - 1, y);
    if (y + 1 < m && !vb[x][y + 1] && vc[x][y + 1] != 'X')
        Visit(x, y + 1);
    if (y - 1 >= 0 && !vb[x][y - 1] && vc[x][y - 1] != 'X')
        Visit(x, y - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    vc.resize(n);
    vb.resize(n);

    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        vc[i].resize(m);
        vb[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> vc[i][j];
            if (vc[i][j] == 'I')
            {
                x = i;
                y = j;
            }
        }
    }

    Visit(x, y);

    if (cnt == 0)
        cout << "TT";
    else
        cout << cnt;

    return 0;
}