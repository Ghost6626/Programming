#include <bits/stdc++.h>
using namespace std;
//MULTIPLE CALLS
//use fibonacci using recursion
int fibo(int n){
    if(n==1||n==2) return 1;
    return fibo(n-1)+fibo(n-2);
}
int main() {
 int n;
 cin>>n;
 cout<<fibo(n);
    return 0;
}