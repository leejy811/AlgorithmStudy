#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }

    int total = 0;

    while (pq.size() > 1)
    {
        int sum = pq.top();
        pq.pop();
        sum += pq.top();
        pq.pop();
        total += sum;
        pq.push(sum);
    }

    cout << total;

    return 0;
}