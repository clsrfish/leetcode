/**
 * @since 2020-01-01 15:54:38
 * 最接近的三数之和
 */
#include <iostream>
#include <vector>
using namespace std;
namespace leetcode_0016 {
string key = "0016";
class Solution {
   public:
    int threeSumClosest(vector<int> &nums, int target) {
        return 0;
    }
};
int main() {
    std::cout << key << ":最接近的三数之和" << std::endl;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = Solution().threeSumClosest(nums, target);
    int expected = 2;
    std::cout << "result:" << result << " expected:" << expected << std::endl;
    return 0;
}
}  // namespace leetcode_0016