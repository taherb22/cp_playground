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
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n;i++){
        cin >> a[i]; 
    }
    if(n==1){
        cout << a[0] << endl;
        return; 
    }
    ll s = 0;
    for (int i = 0; i < n;i++){
        s += a[i]; 
    }
    int i = 2; 
    while(i<n){
        
    }
    s = max(s, abs(a[n - 1] - a[0]));

    cout << s << endl; 
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