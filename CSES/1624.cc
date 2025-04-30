#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<vector<char>> grid(8, vector<char>(8,'-'));
bool valid() {
    for (int i = 0; i<8; i++) {
        int rc = 0, cc = 0;
        for (int j = 0; j<8; j++) {
            rc += (grid[i][j] == 'Q');
            cc += (grid[j][i] == 'Q');
        }
        if (rc > 1 or cc > 1) return false;
    }
    // diagonal check abs(r-c) maybe?
    vector<pair<int,int>> qs;
    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            if (grid[i][j] == 'Q') qs.push_back({i,j});
        }
    }
    for (int i = 0; i<qs.size(); i++) {
        for (int j = i+1; j<qs.size(); j++) {
            if (abs(qs[i].first - qs[j].first) == abs(qs[i].second - qs[j].second))
            return false;
        }
    }
    return true;
}
void f(int qc, int r) {
    if (qc == 8) {
        ans+= valid();
        return;
    }
    if (r >= 8) return;
    for (int i = 0; i<8; i++) {
        if (grid[r][i] != '.') continue;
        char og = grid[r][i];
        grid[r][i] = 'Q';
        f(qc+1,r+1);
        grid[r][i] = og;
    }
}
int main() {
    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            cin>>grid[i][j];
        }
    }
    f(0, 0);
    cout<<ans<<endl;
}
/*
(1,3)
(2,4)
........
...Q....
..*.Q...
........
........
.....**.
...*....
........
*/