#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin>>n>>x;
    vector<pair<int,int>> v;
    for (int i = 0; i<n; i++) {
        int vi;
        cin>>vi;
        v.push_back({vi,i});
    }
    sort(v.begin(),v.end());
    int i = 0, j = n-1;
    while (i < j) {
        if (v[i].first + v[j].first == x) {
            cout<<v[i].second+1<<" "<<v[j].second+1<<endl;
            exit(0);
        }
        if (v[i].first + v[j].first > x) j--;
        else i++;
    }
    cout<<"IMPOSSIBLE\n";
}