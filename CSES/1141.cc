#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i<n; i++) cin>>v[i];
    int i = 0, j = 0;
    map<int,int> mp;
    int ans = 1;
    while (j < n) {
        mp[v[j]]++;
        while (mp[v[j]] > 1 and i < j) {
            mp[v[i]]--;
            i++;
        }
        ans = max(ans,j-i+1);
        j++;
    }
    cout<<ans<<'\n';
}