#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, v;

    cin >> a >> b >> v;

    int add = ((v - a) % (a - b) != 0 && a < v) ? 1 : 0;
    cout << (v - a) / (a - b) + 1 + add;

    return 0;
}