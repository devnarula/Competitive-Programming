#include <bits/stdc++.h>
using namespace std;

int count(vector<int>& scores, int t, set<pair<int,int>>& remgames) {
    if (remgames.size() == 0) {
        // if t won
        int mxscore = 0;
        for (int i = 1; i<=4; i++) {
            if (i != t) mxscore = max(mxscore, scores[i]);
        }
        if (scores[t] > mxscore) return 1;
        return 0;
    }
    auto curgame = *(remgames.begin());
    remgames.erase(remgames.begin());
    int res = 0;
    // curgame win
    scores[curgame.first] += 3;
    res += count(scores, t, remgames);
    scores[curgame.first] -= 3;
    //curgame loss
    scores[curgame.second] += 3;
    res += count(scores, t, remgames);
    scores[curgame.second] -= 3;
    //curgame tie
    scores[curgame.first] += 1;
    scores[curgame.second] += 1;
    res += count(scores, t, remgames);
    scores[curgame.first] -= 1;
    scores[curgame.second] -= 1;
    remgames.insert(curgame);
    return res;
}
int main() {
    int t, g;
    cin>>t>>g;
    set<pair<int,int>> remgames;
    for (int i = 1; i<=4; i++) {
        for (int j = i+1; j <= 4; j++) {
            remgames.insert({i, j});
        }
    }
    vector<int> scores(5, 0);
    for (int i = 0; i<g; i++) {
        int a, b, sa, sb;
        cin>>a>>b>>sa>>sb;
        remgames.erase(remgames.find({a, b}));
        if (sa > sb) {
            scores[a] += 3;
        }
        else if (sb > sa) scores[b] += 3;
        else {
            scores[a] += 1;
            scores[b] += 1;
        }
    }
    cout<<count(scores, t, remgames)<<endl;
}