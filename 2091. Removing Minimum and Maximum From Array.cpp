#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIndex = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        // Remove both from the front
        int front = right + 1;

        // Remove both from the back
        int back = n - left;

        // Remove one from each side
        int frontBack = (left + 1) + (n - right);

        return min({front, back, frontBack});
    }
};

int main() {
    vector<int> nums = {2, 3, 1, 4, 9, 6};

    Solution obj;

    int answer = obj.minimumDeletions(nums);

    cout << "Minimum deletions: " << answer << endl;

    return 0;
}