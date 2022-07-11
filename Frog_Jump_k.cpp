//Youtube Link:- https://www.youtube.com/watch?v=Kmh3rhyEtB8&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=5
//Memoization Approach
#include<bits/stdc++.h>
using namespace std;
int func(int idx,vector<int> height,vector<int> dp,int k){
    if(idx==0){
        return 0;
    }

    if(dp[idx]!=-1){
        return dp[idx];
    }


    int mmSteps=INT_MAX;

    for(int j=1;j<=k;j++){
        if(idx-j>=0){
            int jump=func(idx-j,height,dp,k)+abs(height[idx]-height[idx-1]);
            mmSteps=min(jump,mmSteps);
        }
    }

    return dp[idx]=mmSteps;
}
int solve(int n,vector<int> &height,int k){
    vector<int> dp(n,-1);
    return func(n-1,height,dp,k);
}
int main(){
    vector<int> height{30,10,60,10,60,50};
    int n=height.size();
    int k=2;
    vector<int> dp(n,-1);
    cout<<solve(n,height,k);
}


//Tabulation Approach
int solveUtil(int n,vector<int> &height,vector<int> &dp,int k){
    dp[0]=0;
    for(int i=1;i<n;i++){
        int mmSteps=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump=dp[i-j]+abs(height[i]-height[i-j]);
                mmSteps=min(jump,mmSteps);
            }
        }
        dp[i]=mmSteps;
    }
    return dp[n-1];
}
int solve(int n,vector<int> height,int k){
    vector<int> dp(n,-1);
    return solveUtil(n,height,dp,k);
}
int main(){
    vector<int> height{30,10,60,10,60,50};
    int n=height.size();
    int k=2;
    vector<int> dp(n,-1);
    cout<<solve(n,height,k);
}