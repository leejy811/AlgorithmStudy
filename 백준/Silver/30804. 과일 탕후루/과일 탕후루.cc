#include <bits/stdc++.h>
using namespace std;

long long SumNum(long long idx)
{
    return idx * (idx + 1) / 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    vector<int> v(n);
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int num = 9;
    int start = 0, end = 0;
    int maxSize = 0;
    m[v[0]]++;
    while (start < v.size())
    {
        int cnt = 0;
        for (int i = 1; i <= 9; i++)
        {
            if (m[i] != 0)
                cnt++;
        }

        if (cnt <= 2)
        {
            if (maxSize < end - start + 1)
                maxSize = end - start + 1;

            if (end < v.size() - 1)
                m[v[++end]]++;
            else
                m[v[start++]]--;
        }
        else
        {
            m[v[start++]]--;
        }
    }

    cout << maxSize;

    return 0;
}