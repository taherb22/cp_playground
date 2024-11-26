#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
void solve()
{
    ll n, q;
    cin >> n >> q;
    char a[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        a[0][i] = '.';
        a[i][0] = '.';
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    ll dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (a[i][j] == '*');
        }
    }
 
    while (q--)
    {
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int t = 1;
    while (t--)
    {
        solve();
    }
 
    return 0;
}