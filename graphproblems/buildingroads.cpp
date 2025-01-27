#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ld long double

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5 + 1;
vector<ll> graph[N];
vector<bool> visited(N, false);
void dfs(int pos)
{
    visited[pos] = true;
    for (auto elem : graph[pos])
    {
        if (!visited[elem])
        {
            dfs(elem);
        }
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll ans = 0;
    int lastvisited = 0;
    vector<pair<ll,ll>> v;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {

            dfs(i);
            ans++;
            if(ans>=2){
                v.push_back({i, lastvisited}); 
            }
            lastvisited = i;
        }
    }
    cout << ans - 1 << endl;
    for(auto mm : v){
        cout << mm.first << " " << mm.second << endl;
        
    }
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