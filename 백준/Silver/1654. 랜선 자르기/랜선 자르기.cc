#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k, n;

    cin >> k >> n;

    vector<long long> v(k);
    long long maxLen = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
        maxLen = max(maxLen, v[i]);
    }

    long long top = maxLen;
    long long bottom = 1;
    long long mid;
    long long res = 0;
    while (bottom <= top)
    {
        long long cnt = 0;
        mid = (top + bottom) / 2;
        for (int j = 0; j < k; j++)
        {
            cnt += v[j] / mid;
        }

        if (cnt >= n)
        {
            bottom = mid + 1;
            res = max(res, mid);
        }
        else
        {
            top = mid - 1;
        }
    }

    cout << res;
    return 0;
}