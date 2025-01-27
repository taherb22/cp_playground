#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ld long double
int inv_mod(long long A, ll M)
{
    long long m0 = M;
    long long y = 0, r = 1;
    if (M == 1)
        return 0;
    while (A > 1)
    {
        int q = A / M;
        int t = M;
        M = A % M, A = t;
        t = y;
        y = r - q * y;
        r = t;
    }
    if (r < 0)
        r += m0;
    return r;
}

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int N = 2e5 + 1;
ll inv(ll N)
{
    if (N == 1)
        return 1;
    return (mod - (mod / N) * inv(mod % N) % mod) % mod;
}
void solve()
{
    ll n;
    cin >> n;
    set<ll> divisors;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.insert(i);
            divisors.insert(n / i);
        }
    }
    ll ans = 0;
    for (int i = 2; i * i <= n; i++)
    {
         
        ll s = ((n / i) * ((n / i) + 1)) / 2 - (n / (i + 1)) * (n / (i + 1) + 1) / 2;
        cout << s << " ";
        ans +=(i%mod) * (s%mod) ; 
    }
    ans = ans + n  ; 
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