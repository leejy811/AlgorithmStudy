#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

vector<vector<int>> v;
vector<vector<int>> vis;
pair<int, int> pos;
int wei = 2;

int n;

void bfs()
{
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < n; i++)
        fill(vis[i].begin(), vis[i].end(), 1e9);
    vis[pos.first][pos.second] = 0;

    q.push({ 0, pos.first, pos.second });

    while (!q.empty())
    {
        int c, x, y;
        tie(c, x, y) = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (vis[nx][ny] != 1e9) continue;
            if (wei < v[nx][ny] && v[nx][ny] != 9) continue;

            q.push({ c + 1, nx, ny });
            vis[nx][ny] = c + 1;
        }
    }
}

struct cmp
{
    bool operator()(pair<int, int>& a, pair<int, int>& b)
    {
        int a_cost = v[a.first][a.second];
        int b_cost = v[b.first][b.second];

        if (a_cost >= wei && b_cost >= wei)
            return a_cost > b_cost;
        else if (a_cost >= wei && b_cost < wei)
            return true;
        else if (a_cost < wei && b_cost >= wei)
            return false;
        else
        {
            int a_dist = vis[a.first][a.second];
            int b_dist = vis[b.first][b.second];

            if (a_dist == b_dist)
            {
                if (a.first == b.first)
                    return a.second > b.second;
                else
                    return a.first > b.first;
            }
            else
                return a_dist > b_dist;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    v.resize(n);
    vis.resize(n);
    vector<pair<int, int>> tmp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> fish;
    for (int i = 0; i < n; i++)
    {
        v[i].resize(n);
        vis[i].resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];

            if (v[i][j] == 9)
                pos = { i, j };
            else if (v[i][j])
                tmp.push_back({ i, j });
        }
    }

    bfs();

    for (pair<int, int> p : tmp)
        fish.push(p);

    int res = 0;
    int cnt = 0;
    while (!fish.empty())
    {
        pair<int, int> p = fish.top();
        fish.pop();

        int dist = vis[p.first][p.second];
        if (v[p.first][p.second] >= wei) break;
        if (dist == 1e9) continue;

        v[p.first][p.second] = 0;
        res += dist;
        pos = p;
        cnt++;
        if (cnt == wei)
        {
            wei++;
            cnt = 0;
        }

        bfs();

        vector<pair<int, int>> tmp;
        while (!fish.empty())
        {
            pair<int, int> p = fish.top();
            fish.pop();
            tmp.push_back(p);
        }

        for (pair<int, int> p : tmp)
            fish.push(p);
    }

    cout << res;

    return 0;
}