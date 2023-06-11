/**
 * @file 0027.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 移除元素 https://leetcode-cn.com/problems/remove-element/
 * @version 0.1
 * @date 2021-04-29
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <vector>

#include "../utils/stl_utils.hpp"

namespace leetcode_0027 {
std::string key = "0027";
class Solution {
 public:
  int removeElement(std::vector<int>& nums, int val) {
    int originSize = nums.size();
    if (originSize == 0) {
      return 0;
    }

    int lastIndex = -1;
    for (int curIndex = lastIndex + 1; curIndex < originSize; ++curIndex) {
      if (nums[curIndex] != val) {
        nums[++lastIndex] = nums[curIndex];
      }
    }
    return lastIndex + 1;
  }
};
int main() {
  std::cout << key << ": 移除元素" << std::endl;

  std::vector<int> nums({0, 1, 2, 2, 3, 0, 4, 2});
  int val = 0;
  int newSize = Solution().removeElement(nums, val);
  std::cout << newSize << ": " << vector2str(nums) << std::endl;
  return 0;
}
}  // namespace leetcode_0027