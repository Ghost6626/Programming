// star triangle pattern
#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int n;
    cout<<"enter the number";
    cin>>n;
for (int i = 0; i <n; i++)
{
    for (int j=1;j<=n-i;j++)
    {
        cout<<j<<" ";
    }
    cout<<endl;
    
}
return 0;

}