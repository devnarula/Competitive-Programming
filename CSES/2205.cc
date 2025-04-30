#include <bits/stdc++.h>
using namespace std;

vector<string> f(int n) {
    if (n == 1) {
        return {"0", "1"};
    }
    vector<string> temp = f(n-1);
    vector<string> res;
    for (auto val: temp) {
        res.push_back("0" + val);
    }
    reverse(temp.begin(),temp.end());
    for (auto val: temp) {
        res.push_back("1" + val);
    }
    return res;
}
int main() {
    int n;
    cin>>n;
    vector<string> res = f(n);
    for (auto val: res) {
        cout<<val<<endl;
    }
}
