#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ld long double

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
long long bin_pow(long long a, int b, long long mod)
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

const int N = 2e5;
void solve()
{
    int n;
    cin >> n;

    int x[n];
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    int lastunsortedindex = 0;
    for (int i = 1; i < n; i++)
    {
        // cout << " " << i;
        if (x[i] < x[i - 1])
        {
            lastunsortedindex = i;
        }
    }
   
    ll ans = 0;
    for (int i = 0; i < lastunsortedindex; i++)
    {
        ll y = min(x[i], x[i + 1]);
        x[i] -= y;
        x[i + 1] -= y;
       
    }
    if (is_sorted(x, x + n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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
