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
vector<int> Primes(int n)
{
    vector<bool> is_prime(n + 1, true);

    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) // Sieve of Eratosthenes
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }

    return primes;
}

// Debugging macro
#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'

/*---------------------------------------------------------------------------------------------------
Saurav:Hello Jarvis !!
　 ￣￣\　　　　　　　 ∧＿∧    Jarvis:Namaste Master mai aapki kaise help kar skta hun !!
　　　  \　 ∧＿∧ 　（´<_｀ ）/￣￣
　　　　 （ ´_ゝ`）　/　 ⌒| 
　　　　／　　　＼　 　  |　|
　　　 /　　 /￣￣￣￣/　　|
　 ＿_(__ﾆつ/　   _ / .| .|＿＿＿＿
　 　　　＼/_______/　（u　⊃
---------------------------------------------------------------------------------------------------*/
int ans=INT_MIN;

void rec(vector<int>w,vector<int>p,int wu,int i,int pr,int k){
    if(i==w.size()){
        if(wu<=k){
            ans=max(ans,pr);
        }
        return;
    }

    rec(w,p,wu+w[i],i+1,pr+p[i],k);//pick it

    rec(w,p,wu,i+1,pr,k);//no pick it

    return ;
}
void jarvis()
{
    int n,k;
    cin>>n>>k;

    vector<int>w(n,0),p(n,0);

    for(int i=0;i<n;i++){
        cin>>w[i]>>p[i];
    }

    rec(w,p,0,0,0,k);//initial weight=0, initial index=0, intial profit=0;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    int q = 1;
    // cin >> q;
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