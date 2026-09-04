#include <iostream>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        long long num = n;
        int count = 0;

        while (num != 1) {
            if (num % 2 == 0) {
                num = num / 2;
            }
            else {
                if (num == 3) {
                    num = num - 1;
                }
                else if (num % 4 == 1) {
                    num = num - 1;
                }
                else {
                    num = num + 1;
                }
            }

            count++;
        }

        return count;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Minimum operations: "
         << obj.integerReplacement(n) << endl;

    return 0;
}