/**
 * 回文数
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;
namespace leetcode_0009 {
string key = "0009";
class Solution {
   public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        } else if (x < 10) {
            return true;
        }
        int n = 0;
        int tmpX = x;
        while (tmpX > 0) {
            ++n;
            tmpX /= 10;
        }

        int tmp = 0;
        for (int i = 0; i < n / 2; i++) {
            tmp *= 10;
            tmp += x % 10;
            x /= 10;
        }

        if (n % 2 == 1) {
            x /= 10;
        }

        return tmp == x;
    }
};
int main() {
    std::cout << key << ":回文数" << std::endl;
    vector<int> inputs;
    inputs.push_back(121);
    inputs.push_back(-121);
    inputs.push_back(101);
    inputs.push_back(21120);
    auto iter = inputs.begin();
    while (iter != inputs.end()) {
        cout << Solution().isPalindrome(*iter++) << endl;
    }

    return 0;
}
}  // namespace leetcode_0009