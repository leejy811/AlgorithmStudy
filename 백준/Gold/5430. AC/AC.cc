#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string arr;
        cin >> arr;

        vector<int> v;
        if (arr.size() != 2)
        {
            arr.pop_back();
            string sep = ",";
            int cur_pos = 1, pos;
            while ((pos = arr.find(sep, cur_pos)) != string::npos)
            {
                int len = pos - cur_pos;
                string num = arr.substr(cur_pos, len);
                v.push_back(stoi(num));
                cur_pos = pos + 1;
            }
            string num = arr.substr(cur_pos);
            v.push_back(stoi(num));
        }

        bool isError = false;
        bool isReverse = false;
        for (char c : p)
        {
            if (c == 'R')
            {
                isReverse = !isReverse;
            }
            else
            {
                if (v.empty())
                {
                    isError = true;
                    cout << "error\n";
                    break;
                }
                else
                {
                    auto it = isReverse ? v.end() - 1 : v.begin();
                    v.erase(it);
                }

            }
        }

        if (isError) continue;
        if (v.empty())
        {
            cout << "[]\n";
            continue;
        }

        cout << '[';
        int size = v.size();
        if (isReverse)
        {
            for (int i = size - 1; i > 0; i--)
                cout << v[i] << ',';
            cout << v.front() << "]\n";
        }
        else
        {
            for (int i = 0; i < size - 1; i++)
                cout << v[i] << ',';
            cout << v.back() << "]\n";
        }
    }

    return 0;
}