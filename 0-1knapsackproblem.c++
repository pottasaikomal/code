#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v, k;
    cin >> v >> k;               // max volume and otal no.of items.
    vector<pair<int, int>> a(k); // volume and cost of item i.
    for (int i = 0; i < k; i++)
    {
        int ax, bx;
        cin >> ax >> bx;
        a.push_back({ax, bx});
    }
    int dp[v + 1][k + 1];
    for (int i = 0; i <= v; i++)
        dp[0][i] = 0;
    for (int j = 1; j <= k; j++)
        dp[j][0] = 0;
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (j < a[i-1].second)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = __max(dp[i - 1][j], a[i-1].first + dp[i - 1][j - a[i].first]);
        }
    }
}