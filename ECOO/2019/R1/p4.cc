#include <bits/stdc++.h>
#define int long long
using namespace std;
// note u need to finish the route not just reach stop N
//first bus to finish the route and drop everyone off
struct event {
    int timestamp;
    int busnum;
    int curstop;
    bool operator<(const event& other) const {
        if (timestamp != other.timestamp) return timestamp > other.timestamp;
        return busnum > other.busnum;
    }
};
void solve() {
    int N, M;
    cin>>N>>M;
    vector<queue<int>> stops(N+1);
    multiset<pair<int,int>> waiting;
    int maxBus = 0;
    for (int i = 0; i<M; i++) {
        int S, F;
        cin>>S>>F;
        stops[S].push(F);
        waiting.insert({S, F});
    }
    int res = 2*N - 1, best = 1;
    priority_queue<event> pq;
    for (int bus = 1;; bus++) {
        int curtime = 10 * (bus - 1);
        if (curtime + N - 1 > res) break;
        event e{curtime, bus, 1};
        pq.push(e);
        maxBus = bus;
    }
    vector<multiset<int>> onbus(maxBus+1);
    while (pq.size()) {
        auto e = pq.top();
        pq.pop();
        int active = 0, curtime = e.timestamp, curstop = e.curstop;
        //let passengers off
        while (onbus[e.busnum].size() and *(onbus[e.busnum].begin()) == curstop) {
                onbus[e.busnum].erase(onbus[e.busnum].begin());
                active = 1;
        }
        //board new passengers
        while (onbus[e.busnum].size() < 40 and stops[curstop].size()) {
            pair<int,int> cur = {curstop, stops[curstop].front()};

            //remove the current passenger from waiting queue
            stops[curstop].pop();
            auto it2 = waiting.find(cur);
            if (it2 != waiting.end()) waiting.erase(it2);

            onbus[e.busnum].insert(cur.second);
            active = 1;
        }
        curtime += active;
        if (curstop == N) {
            if (curtime < res || (curtime == res && e.busnum < best)) {
                res = curtime;
                best = e.busnum;
            }
            continue;
        }
        int nxt = N;
        if (onbus[e.busnum].size()) {
            nxt = min(nxt, *(onbus[e.busnum].begin()));
        }
        auto it = waiting.upper_bound({curstop, INT_MAX});
        if (it != waiting.end() && onbus[e.busnum].size() < 40) {
            nxt = min(nxt, it->first);
        }
        curtime += (nxt - curstop);
        pq.push({curtime, e.busnum, nxt});
    }
    cout<<"Bus #"<<best<<endl;
}
int32_t main() {
    int t = 10;
    while (t--) {
        solve();
    }
}