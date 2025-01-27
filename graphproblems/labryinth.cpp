#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define ld long double

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1001;
vector<vector<char>> a(N, vector<char>(N));
vector<vector<bool>> visited(N, vector<bool>(N, false));
#include <bits/stdc++.h>
using namespace std;

class Graph {
    vector<vector<pair<int, int>>> children; // Adjacency list
    vector<int> parent;                     // Stores the parent node for the shortest path tree
    vector<long long> dist;                 // Distance from source
    int n;                                  // Number of nodes

public:
    // Constructor to initialize the graph
    Graph(int sz) {
        n = sz;
        children.resize(n, vector<pair<int, int>>());
        parent.resize(n, -1);
        dist.resize(n, 2e14 + 1); // Initialize distances to a very large value
    }

    // Function to reset distances and parents
    void initialize() {
        for (int i = 0; i < n; i++) {
            dist[i] = 2e14 + 1;
            parent[i] = -1;
        }
    }

    // Dijkstra's algorithm for shortest paths
    void dijkstra(int x) {
        dist[x] = 0;
        set<pair<long long, int>> s = {{0, x}}; // Distance, Node

        while (!s.empty()) {
            pair<long long, int> p = *s.begin();
            int u = p.second;
            s.erase(p);

            for (auto v : children[u]) {
                if (dist[v.first] > dist[u] + v.second) {
                    s.erase({dist[v.first], v.first}); // Remove old distance
                    dist[v.first] = dist[u] + v.second;
                    parent[v.first] = u;
                    s.insert({dist[v.first], v.first}); // Insert updated distance
                }
            }
        }
    }

    // Add edge to the graph
    void add_edge(int u, int v, int weight) {
        children[u].emplace_back(v, weight);
    }

    // Print shortest distances from a source node
    void print_distances() {
        for (int i = 0; i < n; i++) {
            cout << "Node " << i << " -> Distance: " 
                 << (dist[i] == 2e14 + 1 ? -1 : dist[i]) << endl;
        }
    }
};


void bfs(int x, int y, int n ,int m , int targetx, int targety)
{
    queue<pair<pair<int, int>, string>> q;
    q.push({{x, y}, ""});
    while (!q.empty())
    {
        string ch = q.front().second;
        int u = q.front().first.first;
        int v = q.front().first.second;
        q.pop();
        if (targetx == u && targety == v)
        {
            cout << "YES" << endl;
            cout << ch.size() << endl;
            cout << ch << endl;
            return;
        }
        if (u != n - 1 && !visited[u + 1][v] && a[u + 1][v] == '.')
        {
            visited[u + 1][v] = true;
            q.push({{u + 1, v}, ch + "D"});
        }
        if (u != 0 && !visited[u - 1][v] && a[u - 1][v] == '.')
        {
            q.push({{u - 1, v}, ch + "U"});
            visited[u - 1][v] = true;
        }
        if (v != 0 && !visited[u][v + 1] && a[u][v + 1] == '.')
        {
            visited[u][v + 1] = true;
            q.push({{u, v + 1}, ch + "R"});
        }
        if (v != m - 1 && !visited[u][v - 1] && a[u][v - 1] == '.')
        {
            visited[u][v - 1] = true;
            q.push({{u, v - 1}, ch + "L"});
        }
    }
    cout << "NO" << endl;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    a.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    int x, y, targetx, targety;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                x = i;
                y = j;
                a[i][j] = '.'; 
            }
            if (a[i][j] == 'B')
            {
                targetx = i;
                targety = j;
                a[i][j] = '.'; 
            }
        }
    }
  
    bfs(x, y, n, m, targetx, targety);
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