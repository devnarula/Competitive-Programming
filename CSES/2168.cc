#include <bits/stdc++.h>
using namespace std;

struct OS {
    
    int n, sz;
    vector<int> bit;
    OS(int n) : n(n), bit(n, 0), sz(0) {}
    void update(int i, int val) {
        for (++i; i < n; i += (i & -i)) bit[i] += val;
    }
    int pre(int x) {
        int res = 0;
        for (++x; x > 0; x -= (x & -x)) res += bit[x];
        return res;
    }
    int count(int x) { return pre(x) - pre(x-1);}
    void insert(int val) {
        update(val, 1);
        sz++;
    }
    void erase(int val) {
        if (count(val) > 0) {
            update(val,-1);
            sz--;
        }
    }
    int size() {return sz;}
    int gre(int x) {
        return sz - pre(x-1);
    }
    int les(int x) {return pre(x);}
};
int findix(vector<int>& v, int r) {
    return lower_bound(v.begin(), v.end(), r) - v.begin();
}
int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin>>n;
    vector<vector<int>> v;
    vector<int> coords;
    coords.reserve(n);

    for (int i = 0; i<n; i++) {
        int l, r;
        cin>>l>>r;
        v.push_back({l, r,i});
        coords.push_back(r);
    }
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    sort(v.begin(),v.end(), [](auto a, auto b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    });
    OS bit(n+5);
    vector<int> res1(n), res2(n);
    for (auto &vec: v) {
        res1[vec[2]] = bit.gre(findix(coords,vec[1]));
        bit.insert(findix(coords,vec[1]));
    }
    sort(v.begin(),v.end(), [](auto a, auto b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    });
    bit = OS(n+10);
    for (auto &vec: v) {
        res2[vec[2]] = bit.les(findix(coords,vec[1]));
        bit.insert(findix(coords,vec[1]));
    }
    for (auto val: res2) {
        cout<<(val > 0)<<" ";
    }
    cout<<'\n';
    for (auto val: res1) {
        cout<<(val > 0)<<" ";
    }
    cout<<'\n';
}