#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)5e6 + 5;
int spf[maxn];

int main() {
    int n;
    cin>>n;
    for (int i = 0; i<maxn; i++) spf[i] = i;
    for (int i = 2; i * i <= maxn; i++) {
        for (int j = i + i; j <= maxn; j += i) {
            if (spf[i] == i) {
                spf[j] = i;
            }
        }
    }
    int res = 0;
    while (n > 1) {
        if (spf[n] == n) {
            n--;
            res+= n;
        }
        else {
            res += spf[n] - 1;
            n -= n/spf[n];
        }
    }
    cout<<res<<endl;

}