#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;
vector<int> num;

void func(int k)
{
    if (k == m)
    {
        for (int i = 0; i < m; i++)
            cout << v[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < num.size(); i++)
    {
        if (k == 0 || v[k - 1] <= num[i])
        {
            v[k] = num[i];;
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

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (find(num.begin(), num.end(), x) == num.end())
            num.push_back(x);
    }

    sort(num.begin(), num.end());

    func(0);

    return 0;
}