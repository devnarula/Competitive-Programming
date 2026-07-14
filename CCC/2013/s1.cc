#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  int ans = false;
  while (!ans) {
    n++;
    set<int> s;
    int a = n;
    while (a>=1) {
      s.insert(a%10);
      a /= 10;
    }
    int size1 = s.size();
    int size2 = to_string(n).length();
    if (size1 == size2) {
      cout<<n<<endl;
      ans = true;
    }
  }
}