#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;

    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = i + 1;
    }
    
    int idx = 0;
    vector<int> res;
    while (!v.empty())
    {
        idx = (idx + k - 1) % v.size();
        res.push_back(v[idx]);
        v.erase(v.begin() + idx);
    }

    cout << "<";
    for (int i = 0; i < n - 1; i++)
    {
        cout << res[i] << ", ";
    }
    cout << res[n - 1] << ">";

    return 0;
}