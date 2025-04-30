#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n, x;
    cin>>x>>n;
    set<int> s{0,x};
    multiset<int> m{x};
    for (int i = 0; i<n; i++) {
        int pi;
        cin>>pi;
        auto it = s.upper_bound(pi);
        auto it2 = it;
        --it2;
        //it = r, it2 = l
        m.erase(m.find(*it - *it2));
		m.insert(pi - *it2);
		m.insert(*it - pi);
		s.insert(pi);
        auto res = m.end();
        --res;
        cout<<(*res)<<'\n';
    }    
    // there technically is an offline solution by computing largest gap then processing queries in reverse order
    //by removing them
}