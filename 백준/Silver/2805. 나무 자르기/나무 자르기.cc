#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, m;

    cin >> n >> m;

    vector<int> v;
    int maxElem = 0;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);

        if (maxElem < x)
            maxElem = x;
    }

    int left = 0;
    int right = maxElem;
    int mid = 0, res = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] > mid)
                sum += v[i] - mid;
        }

        if (sum >= m)
        {
            left = mid + 1;
            res = max(res, mid);
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << res;

    return 0;
}