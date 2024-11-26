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

int query(int id = 0, int ns = 0 , int ne = n - 1, int val=0)
{
    if (ns == ne)
    {
        if (tree[id] >= val)
        {
            return ns;
        }
        else
        {
            return -1 ;
        }
    }
    int md = ns + (ne - ns) / 2;
    if (tree[2 * id + 1] >= val)
    {
        return query(2 * id + 1, ns, md ,val );
    }
    else
    {
        return query(2 * id + 2, md + 1, ne, val  );
    }
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
    int x;
    for (int i = 0; i < m; i++)
    {
        if(tree[0]<r[i]){
            cout << 0 << endl;
            continue; 
        }
        x = query(0,0,n-1,r[i]);
        cout << x+1 << endl;
        upd(x, h[x] - r[i]);
    }
    return 0;
}
