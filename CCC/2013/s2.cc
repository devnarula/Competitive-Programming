#include <bits/stdc++.h>
using namespace std;

int main() {
  int w, n;
  cin>>w>>n;
  int a[100005];
  for (int i = 0; i<n; i++) {
    cin>>a[i];
  }
  int ans = 0;
  for (int i = 0; i<n; i++) {
    int sum = 0, c = 0;
    for (int j = i; j<min(i+4,n); j++) {
      if (sum <= w) {
        c++;
      }
      sum += a[j];

    }
    if (sum<=w) {
      ans++;
    }
    else {
      ans += c-1;
      break;
    }
  }
  cout<<ans<<endl;
}