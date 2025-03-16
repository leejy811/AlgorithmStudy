#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    vector<string> vn(n);
    vector<string> vm(m);
    for (int i = 0; i < n; i++)
    {
        cin >> vn[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> vm[i];
    }

    sort(vn.begin(), vn.end());
    sort(vm.begin(), vm.end());

    vector<string> inter(n + m);
    vector<string>::iterator iter = set_intersection(vn.begin(), vn.end(), vm.begin(), vm.end(), inter.begin());

    inter.erase(iter, inter.end());

    cout << inter.size() << "\n";
    for (int i = 0; i < inter.size(); i++)
    {
        cout << inter[i] << "\n";
    }

    return 0;
}