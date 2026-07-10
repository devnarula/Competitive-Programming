#include <bits/stdc++.h>
using namespace std;

void solve() {
    int J,W,H;
    cin>>J>>W>>H;
    vector<vector<char>> grid(H, vector<char>(W));
    int start = -1, end = -1;
    for (int i = 0; i<H; i++) {
        for (int j=0; j<W; j++) {
            cin>>grid[i][j];
            if (grid[i][j] == 'L') start = j;
            if (grid[i][j] == 'G') end = j;
        }
    }
    int botrow = H-2;
    while (start != end) {
        if (grid[botrow][start + 1] != '@') {
            start++;
            continue;
        }
        if (grid[botrow][start + 2] == '@') {
            cout << start + 2 << '\n';
            return;
        }
        // we need to jump
        int possible = 0;
        for (int jump = 1; jump <= J && botrow - jump >= 0; jump++) {
            // try each jump
            int pos = 1;
            for (int step = 1; step <= jump; step++) {
                if (grid[botrow - step][start] == '@' or grid[botrow - step][start+2] == '@') pos = 0;
            }
            if (grid[botrow-jump][start+1] == '@') pos = 0;
            if (pos) {
                possible = 1;
                break;
            }
        }
        if (!possible) {
            cout<<start+2<<endl;
            return;
        }
        start+= 2;
    }
    cout<<"CLEAR\n";
}
int main() {
    int t = 10;
    while (t--) {
        solve();
    }
}