#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, p, q;
    vector<int> num;

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        num.push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> p >> q;
        reverse(num.begin() + p - 1, num.begin() + q);
    }

    for (int i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }

    return 0;
}