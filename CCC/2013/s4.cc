#include <bits/stdc++.h>
using namespace std;

int n, m;
bool path(vector<int> adj[], int s, int e) {
    vector<int> vis(n+1, false);
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (auto v: adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v); 
            }
        }
    }
    return vis[e];
}
int main() {
    cin>>n>>m;
    vector<int> adj[n+1];
    for (int i = 0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int s, e;
    cin>>s>>e;
    if (path(adj, s, e)) cout << "yes\n";
    else if (path(adj, e, s)) cout << "no\n";
    else cout << "unknown\n";
}