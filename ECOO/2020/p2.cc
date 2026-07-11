#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void solve();
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
void solve()
{
  vector<vector<pair<int,int>>> stock(1000000);
  map<string,int> id;
  int count = 1;
  int n;
  cin>>n;
  for (int i = 0; i<n; i++) {
    int m;
    cin>>m;
    for (int j = 0; j<m; j++) {
      string item;
      int price, quant;
      cin>>item;
      cin>>price>>quant;
      if (!id[item]) {
        id[item] = count;
        count++;
      }
      int idx = id[item];
      stock[idx].push_back({price,quant});
    }
  }
  for (int i = 1; i<=count; i++) {
    sort(stock[i].begin(),stock[i].end());
  }
  int k;
  cin>>k;
  int ans = 0;
  for (int i = 0; i<k; i++) {
    string item;
    int quant;
    cin>>item; cin>>quant;
    int idx = id[item];
    for (auto val: stock[idx]) {
      int diff = val.second - quant; //available - needed
      if (diff >= 0) { //a lot more available than needed
        ans += val.first * quant;
        quant = 0;
      }
      else {
        ans += val.first * val.second;
        quant -= val.second;
        val.first = 0;
      }
    }
  }
  cout<<ans<<endl;
}
