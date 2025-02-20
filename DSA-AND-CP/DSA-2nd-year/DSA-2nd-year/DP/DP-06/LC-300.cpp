#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/longest-increasing-subsequence/
#define mod 1000000007
class Solution {
public:
    vector<int>arr;
    vector<int>dp;
    int f(int i){
        if(i==0) return 1;

        int mx=INT_MIN;
        if(dp[i]!=-1 ) return dp[i];
        for(int j=0;j<=i-1;j++){
            if(arr[j]<arr[i]){
                mx=max(mx,f(j));
            }
        }
        if(mx==INT_MIN) return dp[i]=1;
        return dp[i]=1+mx;
    }
    int lengthOfLIS(vector<int>& nums) {
        arr.clear();
        arr=nums;
        dp.resize(2505,-1);
        int ans=INT_MIN;

        for(int i=0;i<nums.size();i++){
            ans=max(ans,f(i));
        }
         return ans;
    }
};
int main() {
 
    return 0;
}