#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define int long long
typedef pair<int,int> pi;
#define u_mp unordered_map 
#define u_st unordered_set 
template<typename T>

// Function templates for reading input
void read(T& t) {
    cin >> t;
}
template<typename T, typename... Args>
void read(T& t, Args&... args) {
    cin >> t;
    read(args...);
}

// Debugging macro
#define DEBUG
#ifdef DEBUG
#define debug(x) cout << #x << " = " << x << endl
#else
#define debug(x)
#endif

#define endl '\n'

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    read(q);

    while(q--){
        int n,m,k;
        read(n,m,k);
        if(m==1 || n==k){
            cout<<"NO"<<endl;
        }
        else {
           int c=n/m;
           if(n%m!=0)c++;
           if(n-c<=k) cout<<"NO"<<endl;
           else cout<<"YES"<<endl;
        }
    }
    return 0;
}