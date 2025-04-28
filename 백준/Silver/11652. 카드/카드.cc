#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    map<long long, int> m;
    set<long long> v;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.insert(x);
        m[x]++;
    }

    int maxCnt = 0;
    long long maxVal = 0;
    for (long long x : v)
    {
        if (maxCnt < m[x])
        {
            maxCnt = m[x];
            maxVal = x;
        }
    }

    cout << maxVal;

    return 0;
}