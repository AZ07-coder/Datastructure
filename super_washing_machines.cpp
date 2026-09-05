#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = 0;
        int n = machines.size();

        // Calculate total dresses
        for (int i = 0; i < n; i++) {
            sum += machines[i];
        }

        // If dresses cannot be equally distributed
        if (sum % n != 0) {
            return -1;
        }

        int avg = sum / n;

        int balance = 0;
        int ans = 0;

        // Calculate minimum moves
        for (int i = 0; i < n; i++) {
            int diff = machines[i] - avg;

            balance += diff;

            ans = max(ans, max(abs(balance), diff));
        }

        return ans;
    }
};

int main() {
    int n;

    cout << "Enter number of machines: ";
    cin >> n;

    vector<int> machines(n);

    cout << "Enter dresses in each machine: ";
    for (int i = 0; i < n; i++) {
        cin >> machines[i];
    }

    Solution obj;

    int result = obj.findMinMoves(machines);

    cout << "Minimum number of moves: " << result << endl;

    return 0;
}