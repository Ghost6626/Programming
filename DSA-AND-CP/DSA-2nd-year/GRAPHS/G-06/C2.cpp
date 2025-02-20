#include <bits/stdc++.h>
using namespace std;
// improved version of dsu-----this includes the use of size factor

#define mod 1000000007

class disjoint_set_1
{
    vector<int> parent;
    vector<int> _size;

public:
    disjoint_set_1(int n)
    {
        parent.resize(n);
        _size.resize(n);
    }
    void make_set(int x)
    {
        parent[x] = x;
        _size[x] = 1;
    }

    int _find(int x) // recursive approach to find the parent of x where we are using a tree structure, this have time compleixty of O(log(n))
    {
        if (parent.size() == 0)
        {
            cout << "No groups exist";
            return 0;
        }
        if (parent[x] == x)
            return x;
        /*
              0-----------3        parent[4]=3;  parent[3]=0;   parent[0]=0; break here
             / \         / \
            1   2       4   5

        */
        else
            return _find(parent[x]);
    }

    void _union(int a, int b) {
        int root_a = _find(a);
        int root_b = _find(b);

        if (root_a != root_b) {//we just make the root of the major group of the minor group by just making the major root node the root of minor root node of the previous one
            if (_size[root_a] < _size[root_b]) {
                parent[root_a] = root_b;
                _size[root_b] += _size[root_a];
            } else {
                parent[root_b] = root_a;
                _size[root_a] += _size[root_b];
            }
        }
    }
};
int main()
{
    // Create a disjoint set object with 6 elements
    disjoint_set_1 dsu(6);

    // Initialize sets for each element
    for (int i = 0; i < 6; ++i)
        dsu.make_set(i);

    // Perform union operations
    dsu._union(0, 1);
    dsu._union(1, 2);
    dsu._union(3, 4);
    dsu._union(4, 5);
    dsu._union(0, 3);


    cout<<dsu._find(4)<<endl;
    return 0;
}
