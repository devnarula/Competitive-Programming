#include <bits/stdc++.h>
using namespace std;

double slope(pair<int,int> a, pair<int,int> b) {
    if (b.first == a.first) return INT_MAX;
    return ((b.second - a.second)*1.0)/(1.0*(b.first - a.first));
    
}
void solve() {
    int N;
    cin>>N;
    vector<pair<int,int>> pts;    
    for (int i = 0; i<N; i++) {
        int xi, yi;
        cin>>xi>>yi;
        pts.push_back({xi,yi});
    }
    map<double,int> mp;
    for (int i = 0; i<N; i++) {
        for (int j = i+1; j<N; j++) {
            mp[slope(pts[i], pts[j])]++;
        }
    }
    int res = 0;
    for (int i = 0; i<N; i++) {
        for (int j = i+1; j<N; j++) {
            double slop =slope(pts[i], pts[j]);
            if (slop == INT_MAX) {
                res += mp.count(0);
                if (mp.count(0)) {
                    cout<<i<<" "<<j<<endl;
                }
            }
            else {
                res += mp.count(-1.0 * 1.0/slop);
                if (mp.count(-1.0 * 1.0/slop)) {
                    cout<<i<<" "<<j<<" "<<slop<<endl;
                }
                //subtract lines that go through the point p[i], p[j] with slope 1/slop
                
            }
            
        }
    }
    cout<<res<<endl;
}
int main() {
    int t = 10;
    while (t--) {
        solve();
    }
}