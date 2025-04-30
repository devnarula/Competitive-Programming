#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int n;
    cin>>n;
    vector<int> c(n);
    for (int i = 0; i<n; i++) cin>>c[i];
    sort(c.begin(),c.end());
    // 1 2 2 7 9
    int x = 1;
    for (int i = 0; i<n; i++) {
        if (c[i] > x) {
            cout<<x<<endl;
            exit(0);
        }
        x += c[i];
    }
    cout<<x<<endl;
}