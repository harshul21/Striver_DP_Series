//Youtube Link:- https://www.youtube.com/watch?v=3WaxQMELSkw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=7
//Code Link:- https://www.codingninjas.com/codestudio/problems/house-robber_839733?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

//Memoisation Solution
long long int fun(int idx,vector<int> &arr,vector<long long int> &dp){
    if(idx<0){
        return 0;
    }
    if(dp[idx]!=-1){
        return dp[idx];
    }
    long long int take=arr[idx]+fun(idx-2,arr,dp);
    long long int ntake=fun(idx-1,arr,dp);
    
    return dp[idx]=max(take,ntake);
}
long long int houseRobber(vector<int>& valueInHouse)
{
    vector<int> tmp1,tmp2;
    int n=valueInHouse.size();
    if(n==1){
        return valueInHouse[0];
    }
    for(int i=0;i<n;i++){
        if(i!=0){
            tmp1.push_back(valueInHouse[i]);
        }
        if(i!=n-1){
            tmp2.push_back(valueInHouse[i]);
        }
    }
    vector<long long int> dp(n,-1);
    long long int ans1= fun(tmp1.size()-1,tmp1,dp);
    vector<long long int> dp1(n,-1);
    long long int ans2= fun(tmp2.size()-1,tmp2,dp1);
    return max(ans1,ans2);
}

//Space Optimisation- Stack space reduced
#include <bits/stdc++.h>

using namespace std;

long long int solve(vector<int>& arr){
    int n = arr.size();
    long long int prev = arr[0];
    long long int prev2 =0;
    
    for(int i=1; i<n; i++){
        long long int pick = arr[i];
        if(i>1)
            pick += prev2;
        int long long nonPick = 0 + prev;
        
        long long int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}

long long int robStreet(int n, vector<int> &arr){
    vector<int> arr1;
    vector<int> arr2;
    
    for(int i=0; i<n; i++){
        
        if(i!=0) arr1.push_back(arr[i]);
        if(i!=n-1) arr2.push_back(arr[i]);
    }
    
    long long int ans1 = solve(arr1);
    long long int ans2 = solve(arr2);
    
    return max(ans1,ans2);
}


int main() {

  vector<int> arr{1,5,1,2,6};
  int n=arr.size();
  cout<<robStreet(n,arr);
}