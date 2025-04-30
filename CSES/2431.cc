#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    int32_t q;
    cin>>q;
    while (q--) {
        int k;
        cin>>k;
        int n = k;
        int digs = 1;
        int base = 9;
        while (k - digs * base > 0) {
            k -= digs * base;
            base *= 10;
            digs++;
        }
        //now what?
        //we have (k-1)/digs digs sized blocks
        int delta = (k-1)/digs;
        int start = pow(10LL,digs-1);
        int num = start + delta;
        string s = to_string(num);
        int digit_index = (k - 1) % digs;
        cout<<s[digit_index] <<endl;
        //find within num
        //1234567891011121314151617181920
        //1 digit: 9
        //2 digit: 90
        //3 digit: 900..
        //k = 15
        //k = 6
        //x = 2
        //(10+x): xd+delta = k
        //
        //(10+x)/d       
    }
}