//Youtube Link:- https://www.youtube.com/watch?v=-zI4mrF2Pb4&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=27

#include <bits/stdc++.h>
using namespace std;
void lcs(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]== s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    int len=dp[n][m];
    int i=n;
    int j=m;
    
    int idx=len-1;
    string str="";
    for(int k=1;k<=len;k++){
        str+="$";
    }
    
    while(i>0 and j>0){
        if(s1[i-1]==s2[j-1]){
            str[idx]=s1[i-1];
            idx--;
            i--;
            j--;
        }
        else if(s1[i-1]>s2[j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout<<str;
}
int main() {
	string s1="abcde";
	string s2="bdgek";
	lcs(s1,s2);
	return 0;
}
