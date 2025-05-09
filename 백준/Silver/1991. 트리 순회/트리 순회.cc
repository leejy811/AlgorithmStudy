#include <bits/stdc++.h>
using namespace std;

vector<int> lc;
vector<int> rc;

void preorder(int idx)
{
    if (idx + 'A' == '.') return;

    cout << (char)(idx + 'A');
    preorder(lc[idx]);
    preorder(rc[idx]);
}

void inorder(int idx)
{
    if (idx + 'A' == '.') return;

    inorder(lc[idx]);
    cout << (char)(idx + 'A');
    inorder(rc[idx]);
}

void postorder(int idx)
{
    if (idx + 'A' == '.') return;

    postorder(lc[idx]);
    postorder(rc[idx]);
    cout << (char)(idx + 'A');
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    lc.resize(n);
    rc.resize(n);
    for (int i = 0; i < n; i++)
    {
        char x, y, z;
        cin >> x >> y >> z;
        lc[x - 'A'] = y - 'A';
        rc[x - 'A'] = z - 'A';
    }

    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);

    return 0;
}