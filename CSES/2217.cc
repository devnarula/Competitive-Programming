#include <bits/stdc++.h>
using namespace std;

int v[200005], mp[200005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    vector<int> v(n);
    vector<int> mp(n+1);
    int ans = 1;
    for (int i = 0; i<n; i++) {
        cin>>v[i];
        mp[v[i]] = i;
    }
    for (int i = 1; i<n; i++) ans += mp[i+1] < mp[i];
    map<int,int> s;
    while (m--) {
        int a, b;
        cin>>a>>b;
        --a; --b;
        int v1 = v[a], v2 = v[b]; 
        //we need to count change in cons. inversions
        int delta = 0;
        if (v1 - 1 >= 0) s.insert({v1-1,v1});
        if (v2 - 1 >= 0) s.insert({v2-1,v2});
        if (v2 + 1 <= n) s.insert({v2,v2+1});
        if (v1 + 1 <= n) s.insert({v1,v1+1});
        for (auto &[x, y]: s) delta -= mp[y] < mp[x];
        swap(v[a],v[b]);
        mp[v2] = a; mp[v1] = b;
        for (auto &[x, y]: s) delta += mp[y] < mp[x];
        ans += delta;
        cout<<ans<<'\n';
        s.clear();
    }
    /*
    // 4 2 1 5 3
    inversions 4: 2,1,3 (3)
               2: 1
               1: 0
               5: 1
    total: 5
    consecutive inversions? 2 1
    a-1,a
    a,a+1
    b-1,b
    b,b+1

    // round 1: 1
    // round 2: 2,3
    round 3: 4 5
    swap ix(2,3):
    4 1 2 5 3
    round 1: 1 2 3
    round 2: 4 5
    */
}