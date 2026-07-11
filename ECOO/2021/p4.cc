#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    int k;
    cin>>k;
    k++;
    vector<int> ans;
    for (int d = 2; d * d <= k; d++) {
            while (k % d == 0) {
                ans.push_back(d);
                k /= d;
            }
    }
    //
    if (k > 1) ans.push_back(k);
    int sum = 0;
    for (auto x: ans) sum += x - 1;
    if (sum > 1e5) {
        cout<<"Sad Chris"<<endl;
        return 0;
    }
    cout<<sum<<endl;
    int i = 1;
    for (auto val: ans){
        for (int j = 0; j<val - 1; j++) {
            cout<<i<<" ";
        }
        i++;
    }
    cout<<endl;
}
