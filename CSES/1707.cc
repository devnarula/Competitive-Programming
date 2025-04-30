#include <bits/stdc++.h>
using namespace std;

int cycle = INT_MAX;
vector<int> vis, parent, depth;

int bfs(int start, vector<int> adj[], int n) {
    vector<int> dist(n + 1, -1);
    vector<int> parent(n + 1, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    int min_cycle = INT_MAX;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            } else if (parent[u] != v) {
                min_cycle = min(min_cycle, dist[u] + dist[v] + 1);
            }
        }
    }

    return min_cycle;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vis.resize(n + 1);
    depth.resize(n + 1);
    parent.resize(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, bfs(i, adj, n));
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;

}
