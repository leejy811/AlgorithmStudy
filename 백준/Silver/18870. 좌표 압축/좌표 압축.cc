#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    vector<int> v1(n);
    vector<int> v2(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
        v2[i] = v1[i];
    }

    sort(v1.begin(), v1.end());

    v1.erase(unique(v1.begin(), v1.end()), v1.end());

    map<int, int> m;
    for (int i = 0; i < v1.size(); i++)
    {
        m[v1[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << m[v2[i]] << " ";
    }

    return 0;
}