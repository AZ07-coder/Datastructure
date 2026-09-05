#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> mintill_I(n, 0);

        int mn = INT_MAX;

        // Build suffix minimum
        for (int i = n - 1; i >= 0; i--) {
            mn = min(mn, nums[i]);
            mintill_I[i] = mn;
        }

        int mx = 0;

        // Find first index with score <= k
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);

            int score = mx - mintill_I[i];

            if (score <= k)
                return i;
        }

        return -1;
    }
};

int main() {
    Solution sol;

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = sol.firstStableIndex(nums, k);

    cout << ans << endl;

    return 0;
}