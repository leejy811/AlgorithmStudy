#include <bits/stdc++.h>
using namespace std;

int n, s, cnt = 0;
vector<int> v;

void func(int k, int sum)
{
    if (k == n)
    {
        if (sum == s) cnt++;
        return;
    }
    
    func(k + 1, sum + v[k]);
    func(k + 1, sum);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    v.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    func(0, 0);

    if (s == 0) cnt--;
    cout << cnt;

    return 0;
}