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
void solve()
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    ll a[k];
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    ll ans = 0, nb = 0, p = 1ll;
    for (ll i = 1; i < (1ll << k); i++)
    {
        nb = 0;
        p = 1;
        bool c = 0; 
        for (ll j = 0; j < k; j++)
        {
            if ((i & (1ll << j))!=0)
            {
                nb++ ;
                if(p<=n/a[j]){
                    p*=a[j] ; 
                }
                else{
                    c = 1; 
                    break;
                }
            }
        }
        if(c){
            continue; 
        }
        // cout << n / (n + 1) << endl ; 
        // cout <<  p << " " << nb << endl;
        // cout << n / p << endl;
        // cout << p << " "; 
        if (nb % 2 == 0)
        {
            
            ans -= (n / p);
        }
        else
        {
            ans += (n / p);
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