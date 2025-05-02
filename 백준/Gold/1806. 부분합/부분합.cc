#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long s;

    cin >> n >> s;

    vector<long long> v(n + 1);

    for (int i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        v[i] = v[i - 1] + x;
    }

    int minimum = n + 1;
    int st = 1, en = 1;
    while (st <= n && en <= n)
    {
        if (v[en] - v[st - 1] >= s)
        {
            minimum = min(minimum, en - st + 1);
            st++;
        }
        else
        {
            en++;
        }
    }

    cout << minimum % (n + 1);

    return 0;
}