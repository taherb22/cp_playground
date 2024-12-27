#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ld long double

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int mod = 1e9 + 7;
const int N = 2e5 + 1;
long long bin_pow(long long a, long long b, long long mod)
{
    long long ans = 1;

    while (b)
    {
        if (b % 2)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

void solve()
{
    ll n, x, k;
    cin >> n;
    vector<pair<ll, ll>> powfact(n);
    ll prodk = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> k;
        powfact[i] = {x, k};
    }
    ll s = 1;
    ll numberofdiv = 1, sumofdiv = 1, prodofdiv = 1;
    for (int i = 0; i < n; i++)
    {
        ll coeffsum = (powfact[i].second * (powfact[i].second + 1)) / 2;
        numberofdiv = ((powfact[i].sec  ond + 1) * numberofdiv) % mod;
        prodofdiv = (bin_pow(powfact[i].first,  * coeffsum, mod) * prodofdiv) % mod;
        s = ((powfact[i].first - 1) * s) % mod;
        sumofdiv = (sumofdiv * (bin_pow(powfact[i].first, powfact[i].second + 1, mod) - 1)) % mod;
    }
    s = bin_pow(s, mod - 2, mod);
    sumofdiv = (sumofdiv * s) % mod;
    cout << numberofdiv << " " << sumofdiv << " " << prodofdiv << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;

    while (t--)
    {
        solve();
    }
    return 0;
}