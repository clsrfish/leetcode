/**
 * @file 39.cpp
 * @author clsrfish (clsrfish@gmail.com)
 * @brief https://leetcode-cn.com/problems/combination-sum/
 * @version 0.1
 * @date 2021-10-27
 *
 * @copyright Copyright (c) 2021
 *
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace leetcode_39 {
class Solution {
public:
  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates,
                                               int target) {
    if (target == 0) {
      return {};
    }
    std::sort(candidates.begin(), candidates.end());
    std::vector<std::vector<int>> res;
    std::vector<int> vals;
    combinationSum(candidates, 0, target, vals, res);
    return res;
  }

private:
  void combinationSum(std::vector<int> &candidates, unsigned int index,
                      int target, std::vector<int> &vals,
                      std::vector<std::vector<int>> &res) {
    if (target == 0) {
      res.emplace_back(vals);
      return;
    }
    for (unsigned int i = index; i < candidates.size(); i++) {
      int valI = candidates[i];
      if (valI > target) {
        break;
      }
      vals.push_back(valI);
      combinationSum(candidates, i, target - valI, vals, res);
      vals.pop_back();
    }
  }
};
} // namespace leetcode_39
