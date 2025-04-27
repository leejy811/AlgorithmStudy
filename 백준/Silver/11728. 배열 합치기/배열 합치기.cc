#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    vector<int> va(n);
    vector<int> vb(m);

    for (int i = 0; i < n; i++)
        cin >> va[i];

    for (int i = 0; i < m; i++)
        cin >> vb[i];

    int i = 0, j = 0;
    while (i != n || j != m)
    {
        if (i == n)
        {
            for (; j < m; j++)
                cout << vb[j] << ' ';
            break;
        }
        else if (j == m)
        {
            for (; i < n; i++)
                cout << va[i] << ' ';
            break;
        }

        if (va[i] <= vb[j])
            cout << va[i++] << ' ';
        else
            cout << vb[j++] << ' ';
    }

    return 0;
}