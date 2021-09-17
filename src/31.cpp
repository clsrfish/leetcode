/**
 * @file 31.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief 下一个排列, https://leetcode-cn.com/problems/next-permutation
 * @version 0.1
 * @date 2021-09-13
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

namespace leetcode_31 {
class Solution {
 public:
  void nextPermutation(std::vector<int>& nums) {
    int count = nums.size();
    if (count <= 1) {
      return;
    }

    int i = count - 1;
    for (; i >= 0; i--) {
      if (i + 1 >= count) {
        continue;
      }
      if (nums[i] < nums[i + 1]) {
        int j = i + 1;
        int minIndex = j;
        for (; j < count; j++) {
          if (nums[j] > nums[i] && nums[j] < nums[minIndex]) {
            minIndex = j;
          }
        }
        std::swap(nums[i], nums[minIndex]);
        std::sort(nums.begin() + i + 1, nums.end());
        return;
      }
    }
    std::reverse(nums.begin(), nums.end());
  }
};
}  // namespace leetcode_31
