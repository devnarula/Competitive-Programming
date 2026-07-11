#include <bits/stdc++.h>
#define int long long
using namespace std;

int MOD = 1e9 + 7;
struct context {
    string fname;
    int a, b;
};
int norm(int x) {
    x %= MOD;
    if (x < 0) x += MOD;
    return x;
}
void solve() {
    int N;
    cin>>N;
    vector<pair<string,string>> v;
    stack<context> st;
    for (int i = 0; i<N; i++) {
        string instr;
        getline(cin >> ws, instr); 
        stringstream ss(instr);
        string com;
        ss >> com;
        string param = "";
        if (com != "END") {
            ss >> param;
        }
        v.push_back({com, param});
    }
    st.push({"", 1, 0});
    map<string, pair<int,int>> functions;
    for (auto [com, param]: v) {
        if (com != "END" && com != "CALL" && com != "FUN") {
            auto cur = st.top();
            st.pop();
            int val = stoll(param);
            if (com == "ADD") {
                cur.b = norm(cur.b + val);
            } else if (com == "SUB") {
                cur.b = norm(cur.b - val);
            } else if (com == "MULT") {
                cur.a = cur.a * val % MOD;
                cur.b = cur.b * val % MOD;
            }
            st.push(cur);
        }
        if (com == "CALL") {
            assert(functions.count(param));
            auto func = functions[param];
            auto cur = st.top();
            st.pop();
            cur.a = (cur.a % MOD * func.first % MOD) % MOD;
            cur.b = (cur.b % MOD * func.first % MOD) % MOD;
            cur.b = (cur.b + func.second) % MOD;
            st.push(cur);
        }
        if (com == "END") {
            assert(st.size());
            auto cur = st.top();
            st.pop();
            functions[cur.fname] = {cur.a, cur.b};
        }
        if (com == "FUN") {
            st.push({param, 1, 0});
        }
    }
    assert(st.size());
    auto tp = st.top();
    cout<<(tp.b % MOD)<<endl;

}
int32_t main() {
    int t;
    cin>>t;
    while (t--) {
        solve();
    }
}
