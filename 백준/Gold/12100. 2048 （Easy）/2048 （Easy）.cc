#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
int maxBlock = 0;
int n;

void func(vector<vector<int>> b, int k, int dir)
{
    if (k == 5)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (maxBlock < b[i][j])
                    maxBlock = b[i][j];
        return;
    }

    for (int d = 0; d < dir; d++)
    {
        int tmp[22][22];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                tmp[i][j] = b[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                b[i][j] = tmp[n - 1 - j][i];
    }

    for (int i = 0; i < n; i++)
    {
        int tmp[22] = {};
        int idx = 0;
        for (int j = 0; j < n; j++)
        {
            if (b[i][j] == 0) continue;
            if (tmp[idx] == 0)
                tmp[idx] = b[i][j];
            else if (tmp[idx] == b[i][j])
                tmp[idx++] *= 2;
            else
                tmp[++idx] = b[i][j];
        }
        for (int j = 0; j < n; j++)
            b[i][j] = tmp[j];
    }

    func(b, k + 1, 0);
    func(b, k + 1, 1);
    func(b, k + 1, 2);
    func(b, k + 1, 3);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    board.resize(22);
    for (int i = 0; i < n; i++)
    {
        board[i].resize(22);
        for (int j = 0; j < n; j++)
        {
            cin >> board[i][j];

            if (maxBlock < board[i][j])
                maxBlock = board[i][j];
        }
    }

    func(board, 0, 0);
    func(board, 0, 1);
    func(board, 0, 2);
    func(board, 0, 3);

    cout << maxBlock;

    return 0;
}