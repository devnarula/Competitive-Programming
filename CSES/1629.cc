#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> v;
    for (int i = 0; i<n; i++) {
        int s,e;
        cin>>s>>e;
        v.push_back({e,s});
    }
    sort(v.begin(),v.end());
    int ans = 1, prev = v[0].first;
    //[3,5],[5,8],[4,9]
    for (auto [e,s]: v) {
        if (s >= prev) {
            prev = e;
            ans++;
        }
    }
    cout<<ans<<endl;
}