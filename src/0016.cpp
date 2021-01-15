/**
 * @file 0016.cpp
 * @author your name (you@domain.com)
 * @brief 最接近的三数之和: https://leetcode-cn.com/problems/3sum-closest/
 * @version 0.1
 * @date 2021-01-11
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <algorithm>
#include <iostream>
#include <vector>
namespace leetcode_0016 {
std::string key = "0016";
class Solution {
  public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int sum = 1e5;

        for (int i = 0; i < nums.size() - 2; i++) {
            int low = i + 1, high = nums.size() - 1;
            while (low < high) {
                int newSum = nums[i] + nums[low] + nums[high];
                int rest = target - newSum;
                if (std::abs(rest) < std::abs(target - sum)) {
                    sum = newSum;
                }
                if (rest > 0) {
                    low++;
                } else if (rest < 0) {
                    high--;
                } else {
                    return sum;
                }
            }
        }

        return sum;
    }
};
int main() {
    std::cout << key << ":最接近的三数之和" << std::endl;
    std::vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    int result = Solution().threeSumClosest(nums, target);
    int expected = 2;
    std::cout << "result:" << result << " expected:" << expected << std::endl;
    return 0;
}
} // namespace leetcode_0016