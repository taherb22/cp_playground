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
int divisors_count[(int)1e6 + 1];
void solve()
{
    int n,x;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> x;
        cout << divisors_count[x] << endl; 
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    
    for (int i = 1; i <= 1e6; i++)
    {
        for (int j = i; j <= 1e6; j += i)
        {
            divisors_count[j]++;
        }
    }

    while (t--)
    {
        solve();
    }
    return 0;
}