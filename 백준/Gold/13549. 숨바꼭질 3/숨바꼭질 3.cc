#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visit(110000);
    pq.push({ 0, n });
    while (!pq.empty())
    {
        int sec, pos;
        tie(sec, pos) = pq.top();
        pq.pop();

        if (pos == k)
        {
            cout << sec;
            break;
        }

        if (pos != 0 && pos * 2 < visit.size() && (!visit[pos * 2] || visit[pos * 2] > sec))
        {
            pq.push({ sec, pos * 2 });
            visit[pos * 2] = sec;
        }
        if (pos + 1 < visit.size() && !visit[pos + 1])
        {
            pq.push({ sec + 1, pos + 1 });
            visit[pos + 1] = sec + 1;
        }
        if (pos > 0 && !visit[pos - 1])
        {
            pq.push({ sec + 1, pos - 1 });
            visit[pos - 1] = sec + 1;
        }
    }

    return 0;
}