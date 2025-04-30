#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i<n; i++) cin>>v[i];
    sort(v.begin(),v.end());
    int med = v[n/2], ans = 0;
    for (int i = 0; i<n; i++) ans += abs(med-v[i]);
    cout<<ans<<endl;
}