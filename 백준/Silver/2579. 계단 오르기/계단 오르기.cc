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
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<int> stair(n + 1);
    stair[1] = v[1];
    stair[2] = v[1] + v[2];
    stair[3] = max(v[3] + v[1], v[3] + v[2]);

    for (int i = 4; i <= n; i++)
    {
        stair[i] = max(v[i] + v[i - 1] + stair[i - 3], v[i] + stair[i - 2]);
    }

    cout << stair[n];

    return 0;
}