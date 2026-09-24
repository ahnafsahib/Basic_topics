#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> allsubs;

void generate(vector<int> &subset, int i, vector<int> &nums) {
    if(i == nums.size()) {
        allsubs.push_back(subset);
        return;
    }

    // nums[i] না নিয়ে
    generate(subset, i + 1, nums);

    // nums[i] নিয়ে
    subset.push_back(nums[i]);
    generate(subset, i + 1, nums);
    subset.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for(int &x : nums)
        cin >> x;

    vector<int> subset;

    generate(subset, 0, nums);

    // সব subset print
    for(auto v : allsubs) {
        cout << "{ ";
        for(auto x : v)
            cout << x << " ";
        cout << "}\n";
    }

    return 0;
}
