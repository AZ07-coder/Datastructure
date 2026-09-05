#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int maxi = 0;
        int cnt = 0;

        for (int i = 0; i < arr.size(); i++) {

            maxi = max(maxi, arr[i]);

            if (maxi == i) {
                cnt++;
            }
        }

        return cnt;
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans = sol.maxChunksToSorted(arr);

    cout << ans << endl;

    return 0;
}

