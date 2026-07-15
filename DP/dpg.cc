#include <bits/stdc++.h>
using namespace std;

vector<int> topo, color;
void dfs(vector<int> adj[], int u) {
    for (auto v: adj[u]) {
        if (color[v] == 1) {
            //no cycles in dag
            assert(false);
        }
        if (!color[v]) {
            color[v] = 1;
            dfs(adj, v);
        }
    }
    color[u] = 2;
    topo.push_back(u);
}
int main() {
    int N, M;
    cin>>N>>M;
    vector<int> adj[N+1];
    color.resize(N+1, 0);
    for (int i = 0; i<M; i++) {
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for (int i = 1; i<=N; i++) dfs(adj, i);
    reverse(topo.begin(), topo.end());
    vector<int> dp(N+1, 0);
    for (auto u: topo) {
        for (auto v: adj[u]) dp[v] = max(dp[v], dp[u] + 1);
    }
    int res = 0;
    for (int i = 1; i<=N; i++) res = max(res, dp[i]);
    cout<<res<<endl;
}