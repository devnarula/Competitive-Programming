#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int R, T;
    string A;
    cin>>R>>T>>A;
    map<char, string> rules;
    for (int i = 0; i<R; i++) {
        char C;
        string S;
        cin>>C>>S;
        rules[C] = S;
    }
    int ln = 0;
    char first = A[0], last = A.back();
    map<char, int> mp;
    for (auto c: A) mp[c]++;
    for (int i = 0; i<T; i++) {
        map<char, int> mp2;
        for (auto [c, freq]: mp) {
            // update frequency of each letter
            for (auto c2: rules[c]) {
                mp2[c2] += freq;
            }
        }
        mp = mp2;
        first = rules[first][0];
        last = rules[last].back();
    }
    for (auto [c, freq]: mp) ln += freq;
    cout<<first<<last<<" "<<ln<<endl;
}
int32_t main() {
    int t = 10;
    while (t--) {
        solve();
    }
}