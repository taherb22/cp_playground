#include <bits/stdc++.h>
#define ll long long
using std::cout;
using std::endl;
using std::vector;

vector<int> top_sort;
vector<vector<int>> graph;
vector<bool> visited;
ll mod=1e9+7;
void dfs(int node) {
	for (int next : graph[node]) {
		if (!visited[next]) {
			visited[next] = true;
			dfs(next);
		}
	}
	top_sort.push_back(node);
}

int main() {
	int n, m;
	std::cin >> n >> m;

	graph = vector<vector<int>>(n);
	reach = vector<vector<int>>(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		graph[a - 1].push_back(b - 1);
	}

	visited = vector<bool>(n);
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i);
		}
	}
	std::reverse(top_sort.begin(), top_sort.end());

	vector<int> ind(n);
	for (int i = 0; i < n; i++) { ind[top_sort[i]] = i; }
	bool valid = true;
	for (int i = 0; i < n; i++) {
		for (int j : graph[i]) {
			if (ind[j] <= ind[i]) {
				valid = false;
				break;
			}
		}
		break;
	}
    if(valid){
        for (int node : top_sort){
            cout<<node<<" ";
        }
    }else {
        cout<<"impossible";
    }
}