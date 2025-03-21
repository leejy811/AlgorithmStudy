#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    vector<int> v(n + 1);

    v[2] = 1;
    v[3] = 1;

    for (int i = 4; i <= n; i++)
    {
        int div3 = n, div2 = n, sub1 = n;

        if (i % 3 == 0)
            div3 = v[i / 3];
        if (i % 2 == 0)
            div2 = v[i / 2];
        sub1 = v[i - 1];

        v[i] = min(min(div3, div2), sub1) + 1;
    }

    cout << v[n];

    return 0;
}