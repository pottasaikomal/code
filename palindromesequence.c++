#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int dp[n][n] = {0};
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n - k; i++)
        {
            int j = i + k;
            if (s[i] == s[j] && j - i < 2)
                dp[i][j] = 1;
            else if (s[i] == s[j] && j - i > 1)
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = 0;
        }
    }
    /*
    0,0 0,1 0,2 0,3 0,4 ...... 0,n-1
    ....1,1 1,2 1,3 1,4 ...... 1,n-1
    .
    .
    .
    .
    .
    .
    ........................ n-1,n-1
    finding palindromic sequences from starting index i to index j so if i<j no sequence is formed as we are looking in reverse
    and for every sequence to be palindrome if first and last letters are same then middle sequence should be palindrome that means
    element in before diagonal in dp should be one. so, we are filling dp diagonally.
    */
    // for minimum cost
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    vector<int> c(n);
    c[0] = 0;
    for (int i = 1; i < n; i++)
    {
        c[i] = 1 + c[i - 1];
        for (int j = i; j >= 0; j--)
        {
            if (dp[j][i] == 1)
            {
                if (j != 0)
                    c[i] = __min(c[i], 1 + c[j - 1]);
                else
                    c[i] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << c[i] << " ";
}