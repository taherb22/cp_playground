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
const ll mod = 1e9 + 7; 
ll inv(ll N)
{
    if (N == 1)
        return 1;
    return (mod - (mod / N) * inv(mod % N) % mod) % mod;
    }

ll bin_pow(ll a, int b)
{
    ll ans = 1;
    while (b)
    {
        if (b % 2)
            ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}
void solve()
{
    ll n, x, b;
    cin >> n >> b >> x; 
    if(x==1){
        cout << ((n * (n + 1)) % mod * (n + 2)) % mod << endl;
        return; 
    }
    ll s1 = ((n * bin_pow(x, n + 1)) % mod - ((n + 1) * bin_pow(x, n)) % mod + 1ll) * inv(bin_pow(x - 1ll, 2)) % mod + 2%mod * bin_pow(x, n + 1)%mod * inv(x - 1)%mod + 2ll;
    s1 = s1 % mod; 
    ll s2 = n%mod *( (n+1)%mod * n%mod * bin_pow(x,n-1)) * bin_pow(x-1,2) - 2%mod * (x-1)%mod * (n%mod * bin_pow(x,n+1) - (n+1)%mod * bin_pow(x,n) +1ll )%mod * inv(bin_pow(x-1,4));
    cout << x%mod *(s1%mod - s2%mod ) << endl; 
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}