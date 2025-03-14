#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    if (n == 0)
    {
        cout << 0;
        return 0;
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int remove = floor(n * 0.15 + 0.5);

    sort(v.begin(), v.end());

    v.erase(v.begin(), v.begin() + remove);
    v.erase(v.end() - remove, v.end());

    float sum = accumulate(v.begin(), v.end(), 0);
    cout << floor(sum / v.size() + 0.5);

    return 0;
}