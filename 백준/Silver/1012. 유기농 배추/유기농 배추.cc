#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> v;

void Visit(int idx)
{
    v[idx] = true;
    for (int i : graph[idx])
    {
        if (!v[i])
            Visit(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int m, n, k;

        cin >> m >> n >> k;

        map<pair<int, int>, int> map;
        graph.clear();
        graph.resize(k);
        v.clear();
        v.resize(k);
        for (int j = 0; j < k; j++)
        {
            int x, y;

            cin >> x >> y;
            map[make_pair(x, y)] = j;

            if (map.find(make_pair(x - 1, y)) != map.end())
            {
                int id = map[make_pair(x - 1, y)];

                if (find(graph[j].begin(), graph[j].end(), id) == graph[j].end())
                    graph[j].push_back(id);

                if (find(graph[id].begin(), graph[id].end(), j) == graph[id].end())
                    graph[id].push_back(j);
            }

            if (map.find(make_pair(x + 1, y)) != map.end())
            {
                int id = map[make_pair(x + 1, y)];

                if (find(graph[j].begin(), graph[j].end(), id) == graph[j].end())
                    graph[j].push_back(id);

                if (find(graph[id].begin(), graph[id].end(), j) == graph[id].end())
                    graph[id].push_back(j);
            }

            if (map.find(make_pair(x, y - 1)) != map.end())
            {
                int id = map[make_pair(x, y - 1)];

                if (find(graph[j].begin(), graph[j].end(), id) == graph[j].end())
                    graph[j].push_back(id);

                if (find(graph[id].begin(), graph[id].end(), j) == graph[id].end())
                    graph[id].push_back(j);
            }

            if (map.find(make_pair(x, y + 1)) != map.end())
            {
                int id = map[make_pair(x, y + 1)];

                if (find(graph[j].begin(), graph[j].end(), id) == graph[j].end())
                    graph[j].push_back(id);

                if (find(graph[id].begin(), graph[id].end(), j) == graph[id].end())
                    graph[id].push_back(j);
            }
        }

        int cnt = 0;
        while (find(v.begin(), v.end(), false) != v.end())
        {
            int idx = find(v.begin(), v.end(), false) - v.begin();
            Visit(idx);
            cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}