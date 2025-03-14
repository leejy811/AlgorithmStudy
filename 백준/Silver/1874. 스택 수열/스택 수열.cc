#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    stack<int> s;
    vector<char> res;
    int increase = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        while (s.empty() || s.top() != num)
        {
            if (s.empty())
            {
                if (num < increase)
                {
                    cout << "NO";
                    return 0;
                }
                s.push(++increase);
                res.push_back('+');
            }
            else if (s.top() > num)
            {
                s.pop();
                res.push_back('-');
            }
            else
            {
                if (num < increase)
                {
                    cout << "NO";
                    return 0;
                }
                s.push(++increase);
                res.push_back('+');
            }
        }
        s.pop();
        res.push_back('-');
    }

    for (char c : res)
    {
        cout << c << "\n";
    }

    return 0;
}