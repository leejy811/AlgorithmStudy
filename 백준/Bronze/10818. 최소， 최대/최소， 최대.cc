#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num;
    vector<int> array;

    cin >> num;
    array.resize(num);

    for (int i = 0; i < num; i++)
    {
        cin >> array[i];
    }

    cout << *min_element(array.begin(), array.end()) << " " << *max_element(array.begin(), array.end());

    return 0;
}