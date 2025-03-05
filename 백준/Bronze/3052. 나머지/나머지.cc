#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> num;

    for (int i = 0; i < 10; i++)
    {
        int n;
        cin >> n;
        num.push_back(n % 42);
    }

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    cout << num.size();

    return 0;
}