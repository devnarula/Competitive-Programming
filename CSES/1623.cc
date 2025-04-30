#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<int> v(N);
    for (int i = 0; i<N; i++) {
        cin>>v[i];
    }
    ll ans = INT_MAX;
    for (int mask = 0; mask < (1 << N); mask++) {
        ll a = 0, b = 0;
        for (int j = 0; j<N; j++) {
            if (mask&(1<<j))  a+= v[j];
            else b += v[j];
        }
        ans = min(ans,abs(a-b));
    }
    cout<<ans<<endl;
}