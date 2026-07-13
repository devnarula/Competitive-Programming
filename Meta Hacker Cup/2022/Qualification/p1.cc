#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, K;
    cin>>N>>K;
    vector<int> v(N);
    for (auto &x: v) cin>>x;
    map<int,int> mp;
    for (auto &x: v) mp[x]++;
    int ones = 0, twos = 0;
    for (auto [k, v]: mp) {
        if (v > 2) {
            cout<<"NO\n";
            return;
        }
        if (v == 1) {
            ones++;
        }
        else twos++;
    }
    if (twos + (ones + 1)/2 > K) {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
}
int main() {
    int T;
    cin>>T;
    for (int i = 0; i<T; i++) {
        cout<<"Case #"<<i+1<<":";
        solve();
    }
}