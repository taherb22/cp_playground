#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

vector<int> adj[N], adj_t[N];
vector<int> order;
vector<int> vis(N), id(N);
void dfs1(int v) {
	vis[v] = true;
	for (int u : adj[v]) {
		if (!vis[u]) { dfs1(u); }
	}
	order.push_back(v);
}
void dfs2(int x, int comp) {
	vis[x] = true;

	for (int u : adj_t[x]) {
		if (!vis[u]) { dfs2(u, comp); }
	}
	id[x] = comp;
}

int main() {
	int n, m;
	std::cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj_t[v].push_back(u);
	}

	vis.assign(N, false);

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) { dfs1(i); }
	}

	vis.assign(N, false);
	reverse(begin(order), end(order));
	int comps = 0;
	for (int v : order) {
		if (!vis[v]) {
			comps++;
			dfs2(v, comps);
		}
	}

	for (int i = 1; i <= n; i++) { std::cout << id[i] << " \n"[i == n]; }
}