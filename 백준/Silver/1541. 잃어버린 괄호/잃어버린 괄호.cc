#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;

    cin >> s;

    vector<int> v;
    vector<char> pm;
    int lastId = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-')
        {
            v.push_back(stoi(s.substr(lastId, i)));
            pm.push_back(s[i]);
            lastId = i + 1;
        }
        else if (i == s.size() - 1)
        {
            v.push_back(stoi(s.substr(lastId, s.size())));
        }
    }

    while (find(pm.begin(), pm.end(), '+') != pm.end())
    {
        int i = find(pm.begin(), pm.end(), '+') - pm.begin();
        int sumV = v[i] + v[i + 1];
        pm.erase(pm.begin() + i);
        v.erase(v.begin() + i, v.begin() + i + 2);
        v.insert(v.begin() + i, sumV);
    }

    int sum = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        sum -= v[i];
    }

    cout << sum;

    return 0;
}