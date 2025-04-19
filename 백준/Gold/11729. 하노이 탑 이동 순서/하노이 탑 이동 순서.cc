#include <bits/stdc++.h>
using namespace std;

void func(int a, int b, int n)
{
    if (n == 1)
    {
        cout << a << ' ' << b << '\n';
        return;
    }

    func(a, 6 - a - b, n - 1);

    cout << a << ' ' << b << '\n';

    func(6 - a - b, b, n - 1);
}

int funcCnt(int a, int b, int n)
{
    if (n == 1)
        return 1;

    return funcCnt(a, 6 - a - b, n - 1) + funcCnt(6 - a - b, b, n - 1) + 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    cout << funcCnt(1, 3, n) << '\n';
    func(1, 3, n);

    return 0;
}