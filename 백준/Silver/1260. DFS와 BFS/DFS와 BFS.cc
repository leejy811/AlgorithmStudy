#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visit_v;
queue<int> q;

void Visit_DFS(int idx)
{
    cout << idx + 1 << " ";
    visit_v[idx] = true;
    for (int i : graph[idx])
    {
        if (!visit_v[i])
        {
            Visit_DFS(i);
        }
    }
}

void Visit_BFS(int idx)
{
    cout << idx + 1 << " ";
    visit_v[idx] = true;
    q.push(idx);

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (int i : graph[f])
        {
            if (!visit_v[i])
            {
                cout << i + 1 << " ";
                visit_v[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, v;

    cin >> n >> m >> v;

    graph.resize(n);
    visit_v.resize(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        if (find(graph[a].begin(), graph[a].end(), b) == graph[a].end())
            graph[a].push_back(b);

        if (find(graph[b].begin(), graph[b].end(), a) == graph[b].end())
            graph[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    Visit_DFS(v - 1);
    cout << "\n";

    visit_v.clear();
    visit_v.resize(n);
    Visit_BFS(v - 1);

    return 0;
}