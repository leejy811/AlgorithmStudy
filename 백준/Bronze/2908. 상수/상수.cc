#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    string a, b;

    cin >> a >> b;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    m = max(stoi(a), stoi(b));

    cout << m;

    return 0;
}