#include <bits/stdc++.h>
using namespace std;

int main()
{
    int  n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int index, target;
    cin >> target;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == target)
        {
            index = i;
        }
    }
    cout << index;
    return 0;
}