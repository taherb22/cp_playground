#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5 + 2;

int h[N];
int n;
int tree[4 * N];

int mrg(int x, int y)
{
    return max(x, y);
}

void build(int id = 0, int ns = 0, int ne = n - 1)
{
    if (ns == ne)
    {
        tree[id] = h[ns];
        return;
    }
    int l = 2 * id + 1;
    int r = l + 1;
    int md = ns + (ne - ns) / 2;
    build(l, ns, md);
    build(r, md + 1, ne);
    tree[id] = mrg(tree[l], tree[r]);
}

ll query(int qs, int qe, int id = 0, int ns = 0, int ne = n - 1)
{
    if (ns > qe || qs > ne)
    {
        return -1e7; /// infnity
    }
    if (qs <= ns && qe >= ne)
    {
        return tree[id];
    }
    int l = 2 * id + 1;
    int r = l + 1;
    int md = ns + (ne - ns) / 2;
    return mrg(query(qs, qe, l, ns, md), query(qs, qe, r, md + 1, ne));
}

void upd(int pos, int val, int id = 0, int ns = 0, int ne = n - 1)
{
    if (ns > pos || pos > ne)
    {
        return;
    }
    if (ns == ne)
    {
        tree[id] = val;
        h[ns] = val;
        return;
    }
    int l = 2 * id + 1;
    int r = l + 1;
    int md = ns + (ne - ns) / 2;
    upd(pos, val, l, ns, md);
    upd(pos, val, r, md + 1, ne);
    tree[id] = mrg(tree[l], tree[r]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n >> m;
    int r[m];
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> r[i];
    }

    for (int i = 0; i < 4 * n; i++)
    {
        tree[i] = 0; 
    }
    build();
    int left = 1;
    int right = n;
    int mid;
    int ans;
    for (int i = 0; i < m; i++)
    {
        ans = -1;
        left = 0;
        right = n - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (query(left, mid) >= r[i])
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        cout << ans + 1 << endl;
        if (ans != -1)
        {
            upd(ans, h[ans] - r[i]);
        }
    }
    return 0;
}
