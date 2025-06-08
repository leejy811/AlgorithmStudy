#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str, bomb;
    cin >> str >> bomb;

    string tar;
    for (char c : str)
    {
        tar.push_back(c);
        if (tar.size() >= bomb.size() && tar.substr(tar.size() - bomb.size(), bomb.size()) == bomb)
            for (int i = 0; i < bomb.size(); i++)
                tar.pop_back();
    }

    if (tar.empty())
        cout << "FRULA";
    else
        cout << tar;

    return 0;
}