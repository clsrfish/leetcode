/**
 * @file 0018.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 四数之和 https://leetcode-cn.com/problems/4sum/
 * @version 0.1
 * @date 2021-01-12
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>

namespace leetcode_0018 {
std::string key = "0018";
class Solution {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {
    return nSum(nums, target, 4);
  }

private:
  std::vector<std::vector<int>> nSum(std::vector<int> &nums, int target,
                                     int n) {
    if (n == 2) {
      return twoSum(nums, target);
    } else {

      return twoSum(nums, target);
    }
  }

  std::vector<std::vector<int>> twoSum(std::vector<int> &nums, int target) {
    return std::vector<std::vector<int>>();
  }
};
int main() {
  std::cout << key << ":四数之和" << std::endl;
  return 0;
}
} // namespace leetcode_0018