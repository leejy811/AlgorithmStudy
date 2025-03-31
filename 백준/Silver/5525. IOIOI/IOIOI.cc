#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    string s;

    cin >> n >> m >> s;

    string target;
    string trash = "##";

    for (int i = 0; i < n; i++)
    {
        target += "IO";
    }
    target += "I";

    int cnt = 0;
    while (s.find(target) != string::npos)
    {
        int idx = s.find(target);
        s.replace(idx, 2, trash);
        cnt++;
    }

    cout << cnt;

    return 0;
}