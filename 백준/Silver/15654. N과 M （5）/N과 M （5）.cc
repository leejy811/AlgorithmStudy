#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
vector<int> num;
vector<bool> used;

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
        if (!used[i])
        {
            v[k] = num[i];
            used[i] = true;
            func(k + 1);
            used[i] = false;
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
    num.resize(n);
    used.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    sort(num.begin(), num.end());

    func(0);

    return 0;
}