#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i<n; i++) cin>>v[i];
    //3 8 2 1 5
    //bsearch??
    //LIS??
    multiset<int> s;
    int ans = 0;
    for (int i = 0; i<n; i++) {
        auto it = s.upper_bound(v[i]);
        if (it == s.end()) ans++;
        else s.erase(it);
        s.insert(v[i]);
    }
    cout<<ans<<endl;

}