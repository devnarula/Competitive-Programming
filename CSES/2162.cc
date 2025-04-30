#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    set<int> s;
    for (int i = 1; i<=n; i++) s.insert(i);
    auto it = s.begin();
    ++it;
    while (s.size()) {
       if (it == s.end()) it = s.begin();
       cout<<(*it)<<" ";
       auto it2 = it;
       ++it2;
       if (it2 == s.end()) 
       {
        it2 = s.begin();
       }
       s.erase(it);
       if (s.size() == 0) break;
       ++it2;
       it = it2; 
    }
    cout<<endl;
}