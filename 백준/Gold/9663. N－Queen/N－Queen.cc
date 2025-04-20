#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
vector<bool> used1;
vector<bool> used2;
vector<bool> used3;

void func(int k)
{
    if (k == n)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!used1[i] && !used2[k + i] && !used3[k - i + n - 1])
        {
            used1[i] = true;
            used2[k + i] = true;
            used3[k - i + n - 1] = true;
            func(k + 1);
            used1[i] = false;
            used2[k + i] = false;
            used3[k - i + n - 1] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    used1.resize(n);
    used2.resize(2 * n - 1);
    used3.resize(2 * n - 1);

    func(0);
    cout << cnt;

    return 0;
}