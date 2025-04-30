#include <bits/stdc++.h>
#define int long long
using namespace std;

struct BIT {
    vector<int> v;
    int n;
    BIT(int n) {
        v.resize(n+1,0);
        this->n = n+1;
    }
    BIT(vector<int> vec) : BIT(vec.size()) {
        for (int i = 0; i < vec.size(); i++) range_add(i, i, vec[i]); 
    }
    void add(int i, int val) {
        for (++i; i < n; i += (i & -i)) v[i] += val;
    }
    int pre(int i) {
        int res = 0;
        for (++i; i > 0; i -= (i & -i)) res += v[i];
        return res;
    }
    int sum(int l, int r) {
        if (l == 0) return pre(r);
        else return pre(r) + pre(l-1);
    }
    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }
};

int32_t main() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    BIT bt(v);
    while (q--) {
        int type;
        cin>>type;
        if (type == 1) {
            int a,b,u;
            cin>>a>>b>>u;
            --a;--b;
            bt.range_add(a,b,u);
        }
        else {
            int k;
            cin>>k;
            --k;
            cout<<bt.pre(k)<<endl;
        }
    }
}