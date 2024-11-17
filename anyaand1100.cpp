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
    string s;
    cin >> s;
    set<int> s1;
    int n = s.size();
    for (int i = 0; i < s.size() - 3; i++)
    {
        string ch = "";
        for (int j = i; j <= i + 3; j++)
        {
            ch += s[j];
        }
        if (ch == "1100")
        {
            s1.insert(i);
        }
    }
    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;
        char c;
        cin >> c;
        x--;
        if (n <= 3)
        {
            cout << "NO" << endl;
            continue;
        }
        if (s[x] != c)
        {
            s[x] = c;
            for (int i = x - 3; i <= x; i++)
            {
                if (i >= 0 && i + 3 < s.size())
                {
                    string ch = "";
                    for (int j = i; j <= i + 3; j++)
                    {
                        ch += s[j];
                    }
                    if (ch == "1100")
                    {
                        s1.insert(i);
                    }
                    else
                    {
                        s1.erase(i);
                    }
                }
            }
        }
        if (s1.empty())
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
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