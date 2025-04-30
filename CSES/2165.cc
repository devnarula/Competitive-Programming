#include <bits/stdc++.h>
using namespace std;

//move n from a to c using b
vector<pair<int,int>> res;
void f(int n, int a, int b, int c) {
    if (n == 0) {
        return;
    }
    //move n-1 from a to b using c
    f(n-1,a,c,b);
    //move nth disk from a to c
    res.push_back({a,c});
    //move n-1 disks from b to c using a
    f(n-1,b,a,c);
}
int main() {
    int n;
    cin>>n;
    f(n,1,2,3);
    cout<<res.size()<<endl;
    for (auto [a,b]: res) {
        cout<<a<<" "<<b<<endl;
    }
}