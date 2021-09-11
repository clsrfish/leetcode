/**
 * @file 0026.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 删除有序数组中的重复项 https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 * @version 0.1
 * @date 2021-04-28
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <iostream>
#include <vector>

#include "./utils/stl_utils.hpp"

namespace leetcode_0026 {
std::string key = "0026";
class Solution {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    int originSize = nums.size();
    if (originSize <= 1) {
      return originSize;
    }

    int lastIndex = 0;
    for (int curIndex = lastIndex + 1; curIndex < originSize; curIndex++) {
      if (nums[lastIndex] != nums[curIndex]) {
        nums[++lastIndex] = nums[curIndex];
      }
    }

    // 不需要考虑数组中超出新长度后面的元素.
    // nums.erase(nums.begin() + lastIndex + 1, nums.end());

    return lastIndex + 1;
  }
};
int main() {
  std::cout << key << ": 删除有序数组中的重复项" << std::endl;

  std::vector<int> nums({0, 0, 1, 1, 1, 2, 2, 3, 3, 4});
  Solution().removeDuplicates(nums);
  std::cout << vector2str(nums) << std::endl;
  return 0;
}
}  // namespace leetcode_0026