#include <bits/stdc++.h>
using namespace std;
string nextPermutation(string nums) {
        int ix = -1, n = nums.size();
        for (int i = 0; i<n-1; i++) if (nums[i+1] > nums[i]) ix = i;
        if (ix == -1) {
            reverse(nums.begin(),nums.end());
            return nums;
        }
        int ix2 = -1;
        for (int i = ix+1; i<n; i++) if (nums[i] > nums[ix]) ix2 = i;
        swap(nums[ix],nums[ix2]);
        reverse(nums.begin() + ix + 1, nums.end());
        return nums;
}
int main() {
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    vector<string> res = {s};
    string og = s;
    while (nextPermutation(s) != og) {
        res.push_back(nextPermutation(s));
        s = nextPermutation(s);
    }
    cout<<res.size()<<endl;
    for (auto val: res) {
        cout<<val<<endl;
    }
}