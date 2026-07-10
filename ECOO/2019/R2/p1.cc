#include <bits/stdc++.h>
using namespace std;

void solve() {
    map<string,int> mp;
    int n;
    cin>>n;
    for (int i = 0; i<n; i++) {
        string s;
        cin>>s;
        int at = -1;
        string clean = "";
        for (int j = 0; j<s.length(); j++) {
            if (s[j] == '@') {
                at = j;
                clean += s[j];
                continue;
            }
            if (s[j] == '.' and at == -1) continue;
            if (s[j] == '+') {
                while (j < s.length() and at == -1 and s[j] != '@') j++;
                at = j;
            }
            if (s[j] >= 'A' and s[j] <= 'Z') clean += tolower(s[j]);
            else clean += s[j];
        }
        mp[clean]++;
    }
    cout<<mp.size()<<endl;
}

int main() {
    int t = 10;
    while (t--) {
        solve();
    }
}