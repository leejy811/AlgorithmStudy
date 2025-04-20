#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << v[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (k == 0 || v[k - 1] <= i + 1)
        {
            v[k] = i + 1;
            func(k + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    v.resize(m);

    func(0);

    return 0;
}