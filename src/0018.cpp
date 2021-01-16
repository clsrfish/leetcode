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
#include <algorithm>
#include <iostream>
#include <vector>

namespace leetcode_0018 {
std::string key = "0018";
class Solution {
public:
  std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target) {

    std::sort(nums.begin(), nums.end());
    return nSum(nums, target, 0, 4);
  }

private:
  std::vector<std::vector<int>> nSum(std::vector<int> &nums, int target,
                                     int start, int n) {

    std::vector<std::vector<int>> res;
    auto size = nums.size();
    if (size < n) {
      return res;
    }
    if (n == 2) {
      res = twoSum(nums, target, start);
    } else {
      auto upbounds = size - n;
      for (auto i = start; i <= upbounds; i++) {
        // avoid unnecessary calculations
        if (nums[i] * n > target) {
          break;
        }
        auto tmp = nSum(nums, target - nums[i], i + 1, n - 1);
        if (!tmp.empty()) {
          for (auto &&e : tmp) {
            e.push_back(nums[i]);
            res.push_back(e);
          }
        }
        while (i + 1 <= upbounds && nums[i] == nums[i + 1]) {
          i++;
        }
      }
    }
    return res;
  }

  std::vector<std::vector<int>> twoSum(std::vector<int> &nums, int target,
                                       int start) {
    auto res = std::vector<std::vector<int>>();
    int end = nums.size() - 1;
    int left = start, right = end;
    while (left < right) {
      // avoid unnecessary calculations
      if (nums[right] * 2 > target || nums[left] * 2 < target) {
        break;
      }
      int sum = nums[left] + nums[right];
      if (sum == target) {
        res.push_back({nums[left], nums[right]});
      }
      if (sum >= target) {
        right--;
        while (right > start && nums[right] == nums[right + 1]) {
          right--;
        }
      }
      if (sum <= target) {
        left++;
        while (left < end && nums[left] == nums[left - 1]) {
          left++;
        }
      }
    }

    return res;
  }
};
int main() {
  std::cout << key << ":四数之和" << std::endl;
  std::vector<int> input = {-2, -1, -1, 1, 1, 2, 2};
  std::vector<std::vector<int>> expected = {
      {-2, -1, 1, 2},
      {-1, -1, 1, 1},
  };
  auto output = Solution().fourSum(input, 0);
  bool equal = std::equal(output.begin(), output.end(), expected.begin(),
                          expected.end());
  std::cout << "equal: " << equal << std::endl;
  return 0;
}
} // namespace leetcode_0018