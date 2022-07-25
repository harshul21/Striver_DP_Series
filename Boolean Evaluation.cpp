//Youtube Link:- https://www.youtube.com/watch?v=MM7fXopgyjw&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=53
//Problem Link:- https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

//Recursive DP
typedef long long ll;
int mod = 1000000007;
ll dfs(int i,int j,int isTrue, string &exp,vector<vector<vector<ll>>> &dp){
    if(i>j){
        return 0;
    }
    if(i==j){
        if(isTrue){
            return exp[i]=='T';
        }
        else{
            return exp[i]=='F';
        }
    }
    if(dp[i][j][isTrue]!=-1){
        return dp[i][j][isTrue];
    }
    ll ways=0;
    for(int idx=i+1;idx<=j-1;idx+=2){
        ll lT=dfs(i,idx-1,1,exp,dp);
        ll lF=dfs(i,idx-1,0,exp,dp);
        ll rT=dfs(idx+1,j,1,exp,dp);
        ll rF=dfs(idx+1,j,0,exp,dp);
        
        if(exp[idx]=='&'){
            if(isTrue){
                ways=(ways+ (rT*lT)%mod)%mod;
            }
            else{
                ways = (ways+ (rT*lF)%mod + (rF * lT)%mod + (rF * lF)%mod )%mod;
            }
        }
        else if(exp[idx]=='|'){
            if(isTrue){
                ways=(ways+(lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod )%mod;
            }
            else{
                ways= (ways+ (rF*lF)%mod)%mod;
            }
        }
        else{
            if(isTrue){
                ways=(ways+(lT*rF)%mod + (lF*rT)%mod)%mod;
            }
            else{
                ways=(ways+(lT*rT)%mod + (lF*rF)%mod)%mod;
            }
        }
    }
    return dp[i][j][isTrue]=ways;
}
int evaluateExp(string & exp) {
    int n=exp.size();
    vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(n,vector<ll>(2,-1)));
    return dfs(0,n-1,1,exp,dp);
}