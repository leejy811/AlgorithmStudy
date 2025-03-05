#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    vector<string> res;

    cin >> n;

    for (int i = 0;i < n;i++)
    {
        int num;
        string s, tmp;
        cin >> num >> s;
        for (char c : s)
        {
            string r(num, c);
            tmp += r;
        }
        res.push_back(tmp);
    }

    for (string s : res)
    {
        cout << s << "\n";
    }

    return 0;
}