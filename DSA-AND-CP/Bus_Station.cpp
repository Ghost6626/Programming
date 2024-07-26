#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int, int> pi;
#define u_mp unordered_map
#define u_st unordered_set
#define r_vector(v, n)           \
    vector<int> v(n + 1, 0);     \
    for (int i = 1; i <= n; i++) \
        cin >> v[i];
template <typename T>

// Function templates for reading input
void read(T &t)
{
    cin >> t;
}
template <typename T, typename... Args>
void read(T &t, Args &...args)
{
    cin >> t;
    read(args...);
}
// This is policy based data structure for ordered sets which gives additional features like find_by_order(x) and order_of_key(x);

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }

    return gcd(b % a, a);
}
int binpow(int a, int b)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans *= a;
        }
        a *= a;
        b /= 2;
    }

    return ans;
}
vector<pi> Prime_factors(int n)
{
    vector<pi> factors;

    for (int i = 2; i * i <= n; i++)
    {
        int count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
        factors.push_back({i, count});
    }

    if (n > 1)
    {
        factors.push_back({n, 1});
    }

    return factors;
}
// Debugging macro
#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'

void jarvis()
{
    int n;
    cin >> n;

    r_vector(v, n);

    vector<int> p(n+1,0);

    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] + v[i];
    }
    
    vector<int>d;
    
    for(int i=1;i*i<=p[n];i++){
        if(p[n]%i==0){
            d.push_back(i);
            
            if(n/i!=i){
                d.push_back(p[n]/i);
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i <d.size(); i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += v[j];
            if (sum > d[i])
            {
                break;
            }
            else if (sum == d[i])
            {
                sum = 0;
            }

            if (j == n && sum==0)
            {
                ans.push_back(d[i]);
            }
        }
    }
    sort(ans.begin(),ans.end());
    for (auto it : ans)
    {
        cout << it << " ";
    }

    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    int q = 1;
    // cin>>q;
    while (q--)
    {
        jarvis();
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    cerr << "Time taken: " << duration.count() << " microseconds" << endl;
    return 0;
}

// MISTAKES THAT I AM MAKING //

/*
1. Try to solve 2 problem above your limit
2. Always check if you have declared any variable for input taking have you taken input or not this can give bad_alloc error
3. max and min function are made for taking arguments of same type i.e max(x,y) is valid only if x and y are of same type
4. Always make sure you apply your logic after taking all the inputs do not do mistake like that of https://codeforces.com/problemset/problem/1685/A (circular minmax)
5. always check for memory for global and local variables it may give std allocated throwback error
6. Sometimes it's better to think of subarray approach rather than more brute forces approach .
7. do not go in floating points like that of internal pow function
8. Always beware of loops sometimes for decrementing loops we use i++ instead of i-- !
9. while debugging try to do stress testing .
10. always make prefix sum array of size n+1.



*/