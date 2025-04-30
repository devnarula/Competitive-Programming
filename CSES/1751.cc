#include <bits/stdc++.h>
using namespace std;

vector<int> dp, vis;
void dfs(int u, vector<int>& v, int& ln, queue<int>& p) {
    p.push(u);
    if (vis[u]) {
        ln += dp[u];
        return;
    }
    vis[u] = 1;
    int nxt = v[u] - 1;
    ln++;
    dfs(nxt, v, ln, p);
}
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    dp.resize(n, 0);
    vis.resize(n, 0);
    for (int i = 0; i<n; i++) cin>>v[i];
    for (int i = 0; i<n; i++) {
        if (vis[i]) continue;
        int ln = 0;
        queue<int> p;
        dfs(i, v, ln, p);
        int d = 1;
        while (p.size()) {
            if (p.front() == p.back()) d = 0;
            dp[p.front()] = ln;
            ln -= d;
            p.pop();
        }
    }
    for (auto val: dp) cout<<val<<" ";
    cout<<endl;
}