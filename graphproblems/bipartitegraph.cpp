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
vector<int> team_pupil(N, 0);
vector<bool> visited(N, false);
bool impo = 0; 
void dfs(int pos)
{
    visited[pos] = true;
    for (auto elem : graph[pos])
    {
        if (!visited[elem])
        {
            if(team_pupil[pos]==1){
                team_pupil[elem] = 2; 
            }
            else{
                team_pupil[elem] = 1; 
            }
            dfs(elem);
        }
        else{
            if(team_pupil[elem]==team_pupil[pos]){
                impo = 1; 
               
            }
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
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            team_pupil[i] = 1;
            dfs(i);
        }
    }
    if(impo){
        cout << "IMPOSSIBLE " << endl;
        return; 
    }
    for (int i = 1; i <= n; i++){
        cout << team_pupil[i] << " "; 
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