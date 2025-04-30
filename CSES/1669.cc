#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+5);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(n+5, -1), depth(n+5, 0);
    for(int i = 1; i <= n; i++){
        if(parent[i] == -1){
            queue<int> q;
            q.push(i);
            parent[i] = i;
            depth[i] = 0;
            while(!q.empty()){
                int u = q.front(); 
                q.pop();
                for(int v : adj[u]){
                    if(parent[v] == -1){
                        parent[v] = u;
                        depth[v] = depth[u] + 1;
                        q.push(v);
                    }
                    else if(parent[u] != v){
                        int x = u, y = v;
                        vector<int> path_u, path_v;

                        while(depth[x] > depth[y]){
                            path_u.push_back(x);
                            x = parent[x];
                        }
                        while(depth[y] > depth[x]){
                            path_v.push_back(y);
                            y = parent[y];
                        }
                        while(x != y){
                            path_u.push_back(x);
                            x = parent[x];
                            path_v.push_back(y);
                            y = parent[y];
                        }

                        path_u.push_back(x);
                        reverse(path_v.begin(), path_v.end());
                        for(int node : path_v) 
                            path_u.push_back(node);
                        path_u.push_back(path_u.front());

                        cout << path_u.size() << "\n";
                        for(int node : path_u) 
                            cout << node << " ";
                        cout << "\n";
                        return 0;
                    }
                }
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
