#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i<n; i++) {
        cin>>v[i];
    }
    int ans = INT_MIN, cur = 0;
    for (int i = 0; i<n; i++) {
        cur += v[i];
        ans = max(ans,cur);
        if (cur < 0) cur = 0;
    }
    cout<<ans<<endl;
}