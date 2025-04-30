#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    map<int,int> mp;
    for (int i = 0; i<n; i++) {
        cin>>v[i];
        mp[v[i]] = i;
    }
    int ans = 1, prev = mp[1];
    for (int i = 2; i<=n; i++) {
        if (mp[i] < prev) ans++;
        prev = mp[i];
    }
    cout<<ans<<endl;
}