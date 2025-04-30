#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n), b(m);
    for (int i = 0; i<n; i++) cin>>a[i];
    for (int i = 0; i<m; i++) cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i = 0, j = 0, ans = 0;
    while (i < n and j < m) {
        //45 60 60 80
        //30 60 75
        if (a[i] - k <= b[j] and b[j] <= a[i] + k) {
            i++;
            j++;
            ans++;
        }
        else if (a[i] + k < b[j]) i++;
        else j++;
    }
    cout<<ans<<endl;
}