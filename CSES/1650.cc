#include <bits/stdc++.h>
using namespace std;

struct BIT {
    vector<int> v;
    int n;
    BIT(int n) {
        v.resize(n+1,0);
        this->n = n+1;
    }
    BIT(vector<int> vec) : BIT(vec.size()) {
        for (int i = 0; i<vec.size(); i++) add(i,vec[i]);
    }
    void add(int i, int val) {
        for (++i; i < n; i += (i & -i)) v[i] ^= val;
    }
    int pre(int i) {
        int res = 0;
        for (++i; i > 0; i -= (i & -i)) res ^= v[i];
        return res;
    }
    int sum(int l, int r) {
        if (l == 0) return pre(r);
        else return pre(r) ^ pre(l-1);
    }
};

int main() {
    int n, q;
    cin>>n>>q;
    vector<int> v(n);
    for (int i = 0; i<n; i++) cin>>v[i];
    BIT bt(v);
    while (q--) {
        int a, b;
        cin>>a>>b;
        --a; --b;
        cout<<bt.sum(a,b)<<endl;
    }
}