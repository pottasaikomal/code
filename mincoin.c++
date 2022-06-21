#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,r;
    cin>>m>>r;
    int c[m];
    for(int i=0;i<m;i++) cin>>c[i];
    int dp[r+1];
    dp[0]=0;//zero coins are enough to represent 0.
    //tabulation method.
    for(int i=1;i<=r;i++) dp[i]=INT_MAX;
    for(int i=1;i<=r;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(c[j]<=i && dp[i-c[j]]+1<dp[i])
            dp[i]=(dp[i-c[j]]+1);
        }
    }
}