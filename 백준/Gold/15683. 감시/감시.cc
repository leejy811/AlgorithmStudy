#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> v;
vector<pair<int, int>> cctv;
vector<vector<int>> cctvAngle = { {1, 0, 0, 0}, {1, 0, 1, 0}, {1, 1, 0, 0}, {1, 1, 1, 0}, {1, 1, 1, 1} };
int minArea = 64;

void func(vector<vector<int>> vFunc, int k, int angle)
{
    if (k == cctv.size())
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vFunc[i][j] == 0)
                    cnt++;
            }
        }

        if (minArea > cnt)
            minArea = cnt;
        return;
    }

    int cctvIdx = v[cctv[k].first][cctv[k].second];
    for (int i = angle; i < 4 + angle; i++)
    {
        int idx = i % 4;

        if (cctvAngle[cctvIdx - 1][idx])
        {
            if (i - angle == 0)
            {
                for (int j = cctv[k].first - 1; j >= 0; j--)
                {
                    if (vFunc[j][cctv[k].second] == 6) break;
                    vFunc[j][cctv[k].second] = '#';
                }
            }
            else if (i - angle == 1)
            {
                for (int j = cctv[k].second + 1; j < m; j++)
                {
                    if (vFunc[cctv[k].first][j] == 6) break;
                    vFunc[cctv[k].first][j] = '#';
                }
            }
            else if (i - angle == 2)
            {
                for (int j = cctv[k].first + 1; j < n; j++)
                {
                    if (vFunc[j][cctv[k].second] == 6) break;
                    vFunc[j][cctv[k].second] = '#';
                }
            }
            else if (i - angle == 3)
            {
                for (int j = cctv[k].second - 1; j >= 0; j--)
                {
                    if (vFunc[cctv[k].first][j] == 6) break;
                    vFunc[cctv[k].first][j] = '#';
                }
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        func(vFunc, k + 1, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        v[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];

            if (v[i][j] != 0 && v[i][j] != 6)
                cctv.push_back({ i, j });
        }
    }

    func(v, 0, 0);
    func(v, 0, 1);
    func(v, 0, 2);
    func(v, 0, 3);

    cout << minArea;

    return 0;
}