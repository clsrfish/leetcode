/**
 * @file 33.cpp
 * @author liuxin (clsrfish@gmail.com)
 * @brief https://leetcode-cn.com/problems/search-in-rotated-sorted-array
 * @version 0.1
 * @date 2021-10-26
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <iostream>
#include <string>
#include <vector>

namespace leetcode_33 {
class Solution {
 public:
  int search(std::vector<int>& nums, int target) {
    return binarySeach(nums, 0, nums.size() - 1, target);
  }

  int binarySeach(std::vector<int>& nums, int start, int end, int target) {
    if (start > end) {
      return -1;
    } else if (start == end) {
      return nums[start] == target ? start : -1;
    }
    int mid = start + (end - start) / 2;
    int midVal = nums[mid];
    if (midVal == target) {
      return mid;
    }
    if (midVal >= nums[start]) {  // left sorted
      if (target >= nums[start] && target < midVal) {
        return binarySeach(nums, start, mid - 1, target);
      } else {
        return binarySeach(nums, mid + 1, end, target);
      }
    } else {  // right sorted
      if (target > midVal && target <= nums[end]) {
        return binarySeach(nums, mid + 1, end, target);
      } else {
        return binarySeach(nums, start, mid - 1, target);
      }
    }
    return -1;
  };
};

class Solution2 {
 public:
  int search(std::vector<int>& nums, int target) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      int midVal = nums[mid];
      if (midVal == target) {
        return mid;
      }
      if (midVal >= nums[start]) {  // left sorted
        if (target >= nums[start] && target < midVal) {
          end = mid - 1;
        } else {
          start = mid + 1;
        }
      } else {  // right sorted
        if (target > midVal && target <= nums[end]) {
          start = mid + 1;
        } else {
          end = mid - 1;
        }
      }
    }

    return -1;
  }
};
}  // namespace leetcode_33
