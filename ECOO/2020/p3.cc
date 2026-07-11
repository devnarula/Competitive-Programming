#include <bits/stdc++.h>
using namespace std;

// {top hor, left vert, right vert, mid hor, bot left vert, bot right vert, bot}
int segments[10][7] = {{1, 1, 1, 0, 1, 1, 1},{0, 0, 1, 0, 0, 1, 0},{1, 0, 1, 1, 1, 0, 1}
                ,{1, 0, 1, 1, 0, 1, 1},{0, 1, 1, 1, 0, 1, 0},{1, 1, 0, 1, 0, 1, 1},
                {1, 1, 0, 1, 1, 1, 1},{1, 0, 1, 0, 0, 1, 0},{1, 1, 1, 1, 1, 1, 1},{1, 1, 1, 1, 0, 1, 1}};

vector<vector<char>> gen(int num, pair<int,int> rbound, pair<int,int> colbound) {
    int H = rbound.second - rbound.first + 1;
    int W = colbound.second - colbound.first + 1;
    vector<vector<char>> grid(H, vector<char>(W, '-'));
    
    int vert = (H - 3)/2;
    int hor = W / 2;
    if (num == 1 or num == 4) vert++;
    if (num == 7) vert = (H - 2) / 2;
    //top hor
    int horstart = (num == 3 || num == 7) ? 0 : 1;
    if(segments[num][0]) {
        for (int j = horstart; j < W; j += 2) grid[0][j] = '*';
    }
    // mid hor
    if(segments[num][3]) {
        for (int j = horstart; j < W; j += 2) grid[H/2][j] = '*';
    }
    //bot hor
    if(segments[num][6]) {
        for (int j = horstart; j < W; j += 2) grid[H-1][j] = '*';
    }
    // top left vert
    if (segments[num][1]) {
        for (int i = 0; i<vert; i++) grid[i + segments[num][0]][0] = '*';
    }
    // top right vert
    if (segments[num][2]) {
        for (int i = 0; i<vert; i++) grid[i + segments[num][0]][W - 1] = '*';
    }
    // bot left vert
    if (segments[num][4]) {
        for (int i = 0; i<vert; i++) grid[H - i - 1 - segments[num][6]][0] = '*';
    }
    // bot right vert
    if (segments[num][5]) {
        for (int i = 0; i<vert; i++) grid[H - i - 1 - segments[num][6]][W - 1] = '*';
    }
    return grid;
}
bool valid(int guess, const vector<vector<char>>& grid) {
    int minrow = INT_MAX, maxrow = INT_MIN, mincol = INT_MAX, maxcol = INT_MIN;
    for (int i = 0; i<grid.size(); i++) {
        bool star = false;
        for (int j = 0; j<grid[0].size(); j++) {
            star |= (grid[i][j] == '*');
        }
        if (star) {
            minrow = min(minrow, i);
            maxrow = max(maxrow, i);
        }
    }
    for (int j = 0; j<grid[0].size(); j++) {
        bool star = false;
        for (int i = 0; i<grid.size(); i++) {
            star |= (grid[i][j] == '*');
        }
        if (star) {
            mincol = min(mincol, j);
            maxcol = max(maxcol, j);
        }
    }
    vector<vector<char>> out = gen(guess, {minrow, maxrow}, {mincol, maxcol});
    
    for (int i = minrow; i<= maxrow; i++) {
        for (int j = mincol; j<=maxcol; j++) {
            if (out[i - minrow][j-mincol] != grid[i][j]) {
                return false;
            }
        }
    }
    return true;
}
void solve2() {
    int H, W;
    cin>>H>>W;
    vector<vector<char>> grid(H, vector<char>(W));
    for (int i = 0; i<H; i++) {
        for (int j = 0; j<W; j++) {
            cin>>grid[i][j];
        }
    }
    for (int guess = 0; guess < 10; guess++) {
        if (valid(guess, grid)) {
            cout<<guess;
            return;
        }
    }
    //should never happen
    assert(false);
}

void solve() {
    int N;
    cin>>N;
    for (int i = 0; i<N; i++) {
        solve2();
    }
    cout<<endl;
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
}