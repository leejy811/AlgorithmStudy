#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int a_idx = 0, b_idx = 0;
    vector<int> v;
    while (1)
    {
        int max = 0;
        bool isExist = false;
        int i_st = a_idx, j_st = b_idx;
        for (int i = i_st; i < n; i++)
        {
            for (int j = j_st; j < m; j++)
            {
                if (a[i] == b[j] && max < a[i])
                {
                    max = a[i];
                    a_idx = i + 1;
                    b_idx = j + 1;
                    isExist = true;
                }
            }
        }

        if (!isExist) break;
        v.push_back(max);
    }

    cout << v.size() << '\n';
    for (int x : v)
    {
        cout << x << ' ';
    }

    return 0;
}