#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int c[n],dp[n][n]={-1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            int l=i+j;
            if(s[j]==s[l] && l-j<=1) dp[j][l]=1;
            else if(s[j]==s[l] && l-j>1) dp[j][l]=dp[j+1][l-1];
            else dp[j][l]=0;
        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     cout<<dp[i][j]<<" ";
    //     cout<<'\n';
    // }
    c[0]=0;
    for(int i=1;i<n;i++)
    {
        c[i]=n-1;
        if(dp[0][i]==1) c[i]=0;
        else
        {
            for(int j=i;j>0;j--)
            {
                if(dp[j][i]==1 && c[i]>1+c[j-1])
                c[i]=1+c[j-1];
            }
        }
    }
    cout<<c[6]<<'\n';
}