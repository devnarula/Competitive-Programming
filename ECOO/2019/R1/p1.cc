#include <bits/stdc++.h>
using namespace std;


void solve() {
    int N, M, D;
    cin>>N>>M>>D;
    map<int,int> mp;
    for (int i = 0; i<M; i++) {
        int x;
        cin>>x;
        mp[x]++;
    }
    int res = 0;
    int clean = N;
    for (int i = 1; i<= D; i++) {
        if (!clean) {
            res++;
            clean = N;
        }
        clean--;
        clean += mp[i];
        N += mp[i];
    }
    cout<<res<<endl;
}
int main() {
    int t = 10;
    while (t--) {
        solve();
    }
}