#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int sum = k, cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        cnt += sum / v[i];
        sum -= (sum / v[i]) * v[i];
        if (sum <= 0) break;
    }

    cout << cnt;

    return 0;
}