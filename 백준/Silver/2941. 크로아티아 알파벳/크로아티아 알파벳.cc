#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string target[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
    string s;
    int res = 0;
    int size = 0;

    cin >> s;

    for (string t : target)
    {
        int idx = 0;
        while (1)
        {
            idx = s.find(t, idx);
            if (idx == string::npos) break;
            if (t == "z=" && idx != 0 && s[idx - 1] == 'd')
            {
                idx += t.size();
                continue;
            }
            res++;
            size += t.size();
            idx += t.size();
        }
    }

    cout << res + s.size() - size;


    return 0;
}