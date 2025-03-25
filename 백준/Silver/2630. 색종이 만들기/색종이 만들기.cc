#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int color[2] = { 0, 0 };

void Divide(int n, vector<int> vec)
{
    if (n == 1)
    {
        color[vec[0]]++;
        return;
    }

    if (find(vec.begin(), vec.end(), 0) == vec.end())
        color[1]++;
    else if (find(vec.begin(), vec.end(), 1) == vec.end())
        color[0]++;
    else
    {
        n /= 2;
        for (int i = 0; i < 4; i++)
        {
            vector<int> div(n * n);
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    div[j * n + k] = vec[j * n * 2 + k + n * (i % 2 != 0) + (pow(n * 2, 2) / 2 * (i > 1))];
                }
            }

            Divide(n, div);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    v.resize(n * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            v[i * n + j] = x;
        }
    }

    Divide(n, v);

    cout << color[0] << "\n" << color[1];

    return 0;
}