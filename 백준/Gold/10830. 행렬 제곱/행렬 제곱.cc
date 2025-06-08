#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> init;
int n;

vector<vector<int>> func(long long b, vector<vector<int>> v)
{
    if (b == 2)
    {
        vector<vector<int>> mat(n);
        for (int i = 0; i < n; i++)
        {
            mat[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                    mat[i][j] += (v[i][k] * v[k][j]) % 1000;
                mat[i][j] %= 1000;
            }
        }

        return mat;
    }
    else if (b == 1)
        return v;
    else
    {
        if (b % 2 == 0)
        {
            v = func(b / 2, v);
            vector<vector<int>> mat(n);
            for (int i = 0; i < n; i++)
            {
                mat[i].resize(n);
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                        mat[i][j] += (v[i][k] * v[k][j]) % 1000;
                    mat[i][j] %= 1000;
                }
            }

            return mat;
        }
        else if (b % 2 == 1)
        {
            v = func(b / 2, v);
            vector<vector<int>> mat(n);
            for (int i = 0; i < n; i++)
            {
                mat[i].resize(n);
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                        mat[i][j] += (v[i][k] * v[k][j]) % 1000;
                    mat[i][j] %= 1000;
                }
            }

            vector<vector<int>> mat_res(n);
            for (int i = 0; i < n; i++)
            {
                mat_res[i].resize(n);
                for (int j = 0; j < n; j++)
                {
                    for (int k = 0; k < n; k++)
                        mat_res[i][j] += (mat[i][k] * init[k][j]) % 1000;
                    mat_res[i][j] %= 1000;
                }
            }

            return mat_res;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long b;
    cin >> n >> b;

    init.resize(n);
    for (int i = 0; i < n; i++)
    {
        init[i].resize(n);
        for (int j = 0; j < n; j++)
            cin >> init[i][j];
    }

    init = func(b, init);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << init[i][j] % 1000 << ' ';
        cout << '\n';
    }

    return 0;
}