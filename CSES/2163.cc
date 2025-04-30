#include <bits/stdc++.h>
using namespace std;


struct OS {
    int n;
    int sz;
    vector<int> bit;
    OS(int mxval) : n(mxval), bit(mxval+1,0), sz(0) {}
    void update(int i, int val) {
        for (++i; i < n; i += (i & -i)) bit[i] += val;
    }
    int pre(int i) {
        int res = 0;
        for (++i; i > 0; i -= (i & -i)) {
            res += bit[i];
        }
        return res;
    }
    int count(int i) {
        return pre(i) - pre(i-1);
    }
    void insert(int x) {
        if (count(x) == 0) update(x, 1);
        sz++;
    }
    void erase(int x) {
        if (count(x) > 0) update(x, -1);
        sz--;
    }
    int kth(int k) {
        int lo = 0, hi = n - 1, ans = -1;
        while (lo <= hi) {
            int mi = lo + (hi - lo)/2;
            if (pre(mi) >= k) {
                ans = mi;
                hi = mi - 1;
            }
            else {
                lo = mi + 1;
            }
        }
        return ans;
    }
    int len() {
        return sz;
    }
};

int main() {
    int n, k;
    cin>>n>>k;
    //1 2 3 4 5 6 7
    //i = (i + k)%s
    int i = 0;
    OS os(n+5);
    for (int j = 1; j<=n; j++) os.insert(j);
    while (os.len()) {
        if (os.len() > 0) i = (i + k)%(os.len());
        cout<<os.kth(i + 1)<<endl;
        // cout<<"size:"<<os.len()<<endl;
        os.erase(os.kth(i + 1));
    }
}