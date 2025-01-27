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

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll v[m];
    for (int i = 0; i<m; i++)
        cin >> v[i];
    ll x = 0, l = 0, ans = 0;
    for (int i = 0; i < m - 1; i++)
    {
        if(((v[i]-x-1)/k) == ((v[i+1]-x-1)/k)){
            l++;
            continue;
        }else{
            l++;
            x += l;
            l = 0;
            ans++;
        }
    }
    if(x==m){
        cout << ans;
    }else {
        cout << ans + 1;
    }
}
        int main()
        {
            ios_base::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
            int t = 1;
            //cin >> t;
            while (t--)
            {
                solve();
            }
            return 0;
        }