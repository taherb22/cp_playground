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
    int n,x;
    cin >> n; 
    vector<int>occ(1e6+1,0);
    for (int i = 0; i < n;i++){
        cin >> x;
        occ[x]++; 
    }
    int ans = 1; 
    int nb=0 ;
    for (int i = 1; i <=(int)1e6; i++){
        nb = 0; 
        for (int j = i; j <= 1e6; j += i)
        {
            nb += occ[j]; 
        }
        if(nb>=2){
            ans = max(ans, i); 
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