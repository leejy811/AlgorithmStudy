#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> dp_g(n, 1);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (v[j] < v[i])
                dp_g[i] = max(dp_g[i], dp_g[j] + 1);

    vector<int> dp_l(n, 1);

    for (int i = n - 1; i >= 0; i--)
        for (int j = n - 1; j > i; j--)
            if (v[j] < v[i])
                dp_l[i] = max(dp_l[i], dp_l[j] + 1);

    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, dp_g[i] + dp_l[i]);

    cout << res - 1;

    return 0;
}