#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> v;
vector<bool> virus;
int cnt = 0;

void Visit(int idx)
{
    for (int i : v[idx])
    {
        if (!virus[i])
        {
            virus[i] = true;
            Visit(i);
            cnt++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;

    cin >> n >> m;

    v.resize(n);
    for (int i = 0; i < m; i++)
    {
        int c1, c2;
        cin >> c1 >> c2;

        c1--;
        c2--;
        if (find(v[c1].begin(), v[c1].end(), c2) == v[c1].end())
            v[c1].push_back(c2);

        if (find(v[c2].begin(), v[c2].end(), c1) == v[c2].end())
            v[c2].push_back(c1);
    }

    virus.resize(n);
    virus[0] = true;
    Visit(0);

    cout << cnt;

    return 0;
}