// logest common subsequence
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define vi vector<ll>
#define vii vector<vi>
#define pii pair<ll, ll>
int main()
{
    string a, b;
    cin >> a >> b;
    int m = b.size(), n = a.size();
    int LCS[n + 1][m + 1];
    memset(LCS, -1, sizeof(LCS));
    for (int i = 0; i <= max(n, m); i++)
    {
        if (i <= n)
            LCS[i][0] = 0;
        if (i <= m)
            LCS[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
            }
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            cout << LCS[i][j] << " ";
        cout << endl;
    }
}