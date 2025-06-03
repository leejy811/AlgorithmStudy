#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> prev_max(3);
    cin >> prev_max[0] >> prev_max[1] >> prev_max[2];
    vector<int> prev_min(prev_max);

    for (int i = 1; i < n; i++)
    {
        vector<int> cur(3);
        cin >> cur[0] >> cur[1] >> cur[2];

        vector<int> nxt(3);
        nxt[0] = max(prev_max[0], prev_max[1]) + cur[0];
        nxt[1] = max(prev_max[0], max(prev_max[1], prev_max[2])) + cur[1];
        nxt[2] = max(prev_max[1], prev_max[2]) + cur[2];
        prev_max = nxt;

        nxt[0] = min(prev_min[0], prev_min[1]) + cur[0];
        nxt[1] = min(prev_min[0], min(prev_min[1], prev_min[2])) + cur[1];
        nxt[2] = min(prev_min[1], prev_min[2]) + cur[2];
        prev_min = nxt;
    }

    cout << max(prev_max[0], max(prev_max[1], prev_max[2])) << ' '
        << min(prev_min[0], min(prev_min[1], prev_min[2]));

    return 0;
}