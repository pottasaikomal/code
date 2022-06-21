#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x; // size of array and sum required.
    int a[n], dp[n + 1][x + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
        /*
        Tabular form method.
        Here time complexity is o(n*x).
        SS subset sum.
        SS(A, n, X) = true if X = 0
        SS(A, n, X) = false if n = 0 and X > 0
        SS(A, n, X) = SS(A, n-1, X) if X<A[n-1]
        SS(A, n, X) = SS(A, n-1, X) || SS(A, n-1, X – A[n-1])
        */
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= x; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            if (j < a[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    if(dp[n][x]) cout<<"yes the possible sum can be created"<<'\n';
    else cout<<"no possible outcome for x"<<'\n';
}