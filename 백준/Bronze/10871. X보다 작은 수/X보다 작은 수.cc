#include <bits/stdc++.h>

using namespace std;

int target;

bool findCondition(int n)
{
    if (n < target)
        return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int num;
    vector<int> array;

    cin >> num >> target;
    array.resize(num);

    for (int i = 0; i < num; i++)
    {
        cin >> array[i];
    }

    vector<int>::iterator iter = array.begin();

    iter = find_if(iter, array.end(), findCondition);
    cout << array[iter - array.begin()] << " ";

    while (1)
    {
        iter = find_if(iter + 1, array.end(), findCondition);
        if (iter == array.end()) break;
        cout << array[iter - array.begin()] << " ";
    }

    return 0;
}