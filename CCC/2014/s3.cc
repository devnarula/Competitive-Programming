#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (auto &x: v) cin>>x;
    reverse(v.begin(), v.end());
    stack<int> st;
    int cur = 1;
    int i =0;
    while (i<n) {
        int x=v[i];
        if (x == cur) {
            cur++;
            i++;
        }
        else {
            if (st.size() and st.top() == cur) {
                st.pop();
                cur++;
            }
            else {
                st.push(x);
                i++;
            }
        }
    }
    while (st.size() and st.top() == cur++) st.pop();
    cout<<(cur == n+1 ? "Y\n" : "N\n");
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
}
