#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ld long double

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1000 ;

vector<vector<char>> a(N, vector<char>(N));
vector<vector<bool>> visited(N, vector<bool>(N, false ));

void dfs(int x, int y, int n, int m )
{
    visited[x][y] = true;
    if(a[x][y]=='#'){
        return; 
    }
    if (y != m - 1 && a[x][y + 1] == '.' && !visited[x][y+1] )
    {
        dfs(x, y + 1, n, m );
    }
    if (y != 0 && a[x][y - 1] == '.' && !visited[x][y-1])
    {
        dfs(x, y - 1, n, m );
    }
    if (x != n - 1 && a[x + 1][y] == '.' && !visited[x+1][y])
    {
        dfs(x + 1, y, n, m );
    }
    if (x != 0 && a[x - 1][y] == '.' && !visited[x-1][y])
    {
        dfs(x - 1, y, n, m );
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    // cout << n << " " << m << endl; 
    a.resize(n, vector<char>(m));

    visited.resize(n, vector<bool>(m, false ));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            
           
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && a[i][j] == '.')
            {
                ans++;
                dfs(i,j,n, m ) ; 
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}