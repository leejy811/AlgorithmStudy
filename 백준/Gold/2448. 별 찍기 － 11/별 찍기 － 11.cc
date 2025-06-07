#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> star;

void func(int x, int y, int n)
{
    if (n == 3)
    {
        star[x][y] = '*';
        star[x + 1][y - 1] = '*';
        star[x + 1][y + 1] = '*';
        star[x + 2][y - 2] = '*';
        star[x + 2][y - 1] = '*';
        star[x + 2][y] = '*';
        star[x + 2][y + 1] = '*';
        star[x + 2][y + 2] = '*';
    }
    else
    {
        func(x, y, n / 2);
        func(x + n / 2, y - n / 2, n / 2);
        func(x + n / 2, y + n / 2, n / 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    star.resize(n);
    for (int i = 0; i < n; i++)
    {
        star[i].resize(2 * n - 1);
        fill(star[i].begin(), star[i].end(), ' ');
    }

    func(0, n - 1, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            cout << star[i][j];
        }
        cout << '\n';
    }

    return 0;
}