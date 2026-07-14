#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin>>n;
  string a[40], b[40];
  for (int i = 0; i<n; i++) {
    cin>>a[i];
  }
  for (int i = 0; i<n; i++) {
    cin>>b[i];
  }
  map<string,string> s;
  bool ans = true;
  for (int i = 0; i<n; i++) {
    if ( s.find(a[i]) == s.end() ) {
        s[a[i]] = b[i];
        s[b[i]] = a[i];
  } else {
   
  if (s[a[i]] != b[i]) {
    ans = false;
  }
}
 if ((s[a[i]] == a[i]) || (s[b[i]] == b[i])) {
      ans = false;
    }
  }
  if (ans) {
    cout<<"good\n";
  }
  else {
    cout<<"bad\n";
  }
}
