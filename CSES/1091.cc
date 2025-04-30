#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    multiset<int> h;
    for (int i = 0; i<n; i++) {
        int hi;
        cin>>hi;
        h.insert(hi);
    }    
    for (int i = 0; i<m; i++) {
        int ti;
        cin>>ti;
        //search for largest x <= ti
        //ub: smallest x > ti
        auto it = h.upper_bound(ti);
        if (it == h.begin()) {
            cout<<-1<<endl;
        }
        else {
            --it;
            cout<<(*it)<<endl;
            h.erase(it);
        }
    }
}