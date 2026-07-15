#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin>>N;
    vector<vector<int>> acts;
    for (int i = 0; i<N; i++) {
        int ai, bi, ci;
        cin>>ai>>bi>>ci;
        acts.push_back({ai,bi,ci});
    }
    vector<vector<int>> dp(N, vector<int>(3, 0));
    for (int i = 0; i<N; i++) {
        for (int j = 0; j<3; j++) {
            dp[i][j] = acts[i][j];
            if (i) {
                dp[i][j] += max(dp[i-1][(j+1 + 3)%3], dp[i-1][(j-1 + 3)%3]);
            }
        }
    }
    cout<<max({dp[N-1][0], dp[N-1][1], dp[N-1][2]})<<endl;
}