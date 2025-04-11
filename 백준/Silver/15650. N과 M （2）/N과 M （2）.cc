#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    vector<bool> v(n);
    fill(v.begin(), v.begin() + m, true);

    do {
        for (int i = 0; i < n; i++) {
            if (v[i])
                cout << i + 1 << ' ';
        }

        cout << '\n';
    } while (prev_permutation(v.begin(), v.end()));

    return 0;
}