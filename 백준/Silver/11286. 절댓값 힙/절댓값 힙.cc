#include <bits/stdc++.h>
using namespace std;

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second > b.second;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	int n;

    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

	for (int i = 0; i < n; i++)
	{
        int x;

        cin >> x;

        if (x == 0)
        {
            if (pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << pq.top().first << '\n';
                pq.pop();
            }
        }
        else
            pq.push(make_pair(x, abs(x)));
	}

    return 0;
}