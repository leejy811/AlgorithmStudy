#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    stack<int> s;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
            s.pop();
        else
            s.push(num);
    }

    int sum = 0;
    while (!s.empty())
    {
        sum += s.top();
        s.pop();
    }

    cout << sum;

    return 0;
}