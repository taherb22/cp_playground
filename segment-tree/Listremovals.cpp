#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int Mod = 1e9 + 7;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
void solve()
{
    int n;
    cin >> n;
    int x;
    ordered_set s;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        s.insert(i);
        mp[i] = x;
    }
    int p;
    for (int i = 0; i < n; i++)
    {
        cin >> p;
        p--;
        auto it = s.find_by_order(p);
        cout << mp[*(it)] << " ";
        s.erase(s.find(*it));
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