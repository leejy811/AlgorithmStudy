#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void postOrder(int st, int en)
{
    if (en - st == 1)
    {
        cout << v[st] << '\n';
        return;
    }

    int idx = en;
    for (int i = st + 1; i < en; i++)
    {
        if (v[i] > v[st])
        {
            idx = i;
            break;
        }
    }

    if (idx != st + 1)
        postOrder(st + 1, idx);

    if (idx != en)
        postOrder(idx, en);

    cout << v[st] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    while (cin >> x)
        v.push_back(x);

    postOrder(0, v.size());

    return 0;
}