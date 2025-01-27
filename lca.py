class LCA:
    def __init__(self, adj, root=0):
        self.n = len(adj)
        self.height = [0] * self.n
        self.first = [0] * self.n
        self.euler = []
        self.visited = [False] * self.n
        self.dfs(adj, root)
        m = len(self.euler)
        self.segtree = [0] * (4 * m)
        self.build(1, 0, m - 1)

    def dfs(self, adj, node, h=0):
        self.visited[node] = True
        self.height[node] = h
        self.first[node] = len(self.euler)
        self.euler.append(node)
        for to in adj[node]:
            if not self.visited[to]:
                self.dfs(adj, to, h + 1)
                self.euler.append(node)

    def build(self, node, b, e):
        if b == e:
            self.segtree[node] = self.euler[b]
        else:
            mid = (b + e) // 2
            self.build(node * 2, b, mid)
            self.build(node * 2 + 1, mid + 1, e)
            left = self.segtree[node * 2]
            right = self.segtree[node * 2 + 1]
            self.segtree[node] = left if self.height[left] < self.height[right] else right

    def query(self, node, b, e, L, R):
        if b > R or e < L:
            return -1
        if b >= L and e <= R:
            return self.segtree[node]
        mid = (b + e) // 2
        left = self.query(node * 2, b, mid, L, R)
        right = self.query(node * 2 + 1, mid + 1, e, L, R)
        if left == -1:
            return right
        if right == -1:
            return left
        return left if self.height[left] < self.height[right] else right

    def lca(self, u, v):
        left = self.first[u]
        right = self.first[v]
        if left > right:
            left, right = right, left
        return self.query(1, 0, len(self.euler) - 1, left, right)