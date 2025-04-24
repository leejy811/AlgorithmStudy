#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    vector<pair<int, int>> house;
    vector<pair<int, int>> chicken;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;

            if (x == 1)
                house.push_back({ i, j });
            else if (x == 2)
                chicken.push_back({ i, j });
        }
    }

    vector<bool> v(chicken.size());
    for (int i = v.size() - m; i < v.size(); i++)
        v[i] = true;

    int minimum = INT_MAX;
    do
    {
        int dist = 0;
        for (pair<int, int> h : house)
        {
            int tmp = INT_MAX;
            for (int i = 0; i < v.size(); i++)
            {
                if (!v[i]) continue;

                tmp = min(tmp, abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second));
            }
            dist += tmp;
        }

        minimum = min(minimum, dist);
    } while (next_permutation(v.begin(), v.end()));

    cout << minimum;

    return 0;
}