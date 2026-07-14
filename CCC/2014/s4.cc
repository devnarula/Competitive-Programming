#include <bits/stdc++.h>
#define int long long
using namespace std;

struct point {
    int x1, y1, x2, y2, ti;
};
int32_t main() {
    int N, T;
    cin>>N>>T;
    vector<int> xvals, yvals;
    vector<point> pts;
    for (int i = 0; i<N; i++) {
        int x1, y1, x2, y2, ti;
        cin>>x1>>y1>>x2>>y2>>ti;
        xvals.push_back(x1);
        xvals.push_back(x2);
        yvals.push_back(y1);
        yvals.push_back(y2);
        pts.push_back({x1, y1, x2, y2, ti});
    }
    sort(xvals.begin(), xvals.end());
    sort(yvals.begin(), yvals.end());
    
    xvals.erase(unique(xvals.begin(), xvals.end()), xvals.end());
    yvals.erase(unique(yvals.begin(), yvals.end()), yvals.end());
    
    vector<vector<int>> diff(xvals.size() + 1, vector<int>(yvals.size() + 1));
    for (auto [x1, y1, x2, y2, ti]: pts) {
        x1 = lower_bound(xvals.begin(), xvals.end(), x1) - xvals.begin();
        x2 = lower_bound(xvals.begin(), xvals.end(), x2) - xvals.begin();
        y1 = lower_bound(yvals.begin(), yvals.end(), y1) - yvals.begin();
        y2 = lower_bound(yvals.begin(), yvals.end(), y2) - yvals.begin();
        diff[x1][y1] += ti;
        diff[x2][y1] -= ti;
        diff[x1][y2] -= ti;
        diff[x2][y2] += ti;
    }
    // compute psa
    for (int i = 0; i<xvals.size(); i++) {
        for (int j = 0; j<yvals.size(); j++) {
            if (i) diff[i][j] += diff[i-1][j];
            if (j) diff[i][j] += diff[i][j-1];
            if (i and j) diff[i][j] -= diff[i-1][j-1];
        }
    }
    int res = 0;
    for (int i = 0; i + 1 < xvals.size(); i++) {
        for (int j = 0; j + 1 < yvals.size(); j++) {
            if (diff[i][j] >= T) {
                int width = xvals[i + 1] - xvals[i];
                int height = yvals[j + 1] - yvals[j];
                res += width * height;
            }
        }
    }
    cout<<res<<endl;
}