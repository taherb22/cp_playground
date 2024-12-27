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
    int n, k;
    cin >> n >> k;
    int a[n];
    map<int, int> mpa;
    set<int> sa;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mpa[a[i]]++;
        sa.insert(a[i]);
    }
    int b[n];
    set<int> sb;
    map<int, int> mpb;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        mpb[b[i]]++;
        sb.insert(b[i]);
    }
    ll ans = 0;
    sort(a, a + n);
    sort(b, b + n);
    int x = 0;
    for (auto elem : sa)
    {
        auto it = lower_bound(b, b + n, elem);
        it--;
        ll nbb = it - b + 1;
        // cout << nbb << endl;
        if (x - nbb <= k)
        {
            ans = max(ans, (ll)(n - nbb) * elem);
        }
        x += mpa[elem];
    }
    x = 0;
    // cout << ans << endl;
    for (auto elem : sb)
    {
        auto it = lower_bound(a, a + n, elem);
        it--;
        // cout << *it << endl;
        ll nba = it - a + 1;
        // cout << nba << endl;
        // cout << *it << endl;
        if (nba - x <= k)
        {
            ans = max(ans, (ll)(n - x) * elem);
        }
        x += mpb[elem];
    }
    cout << ans << endl;
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